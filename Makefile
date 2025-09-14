.DEFAULT_GOAL := ALL
MAKE_FILE_PATH := $(abspath $(lastword $(MAKEFILE_LIST)))
MAKE_FILE_DIR  := $(dir $(MAKE_FILE_PATH))
MAKE_CONFIG_DIR           = $(MAKE_FILE_DIR).make
ifneq ($(wildcard $(MAKE_CONFIG_DIR)/localconfig),)
include $(MAKE_CONFIG_DIR)/localconfig
endif
ifneq ($(wildcard $(MAKE_CONFIG_DIR)/depend.dir/*.mk),) 
PROJECT_MODULE_MAKEFILES += $(wildcard $(MAKE_CONFIG_DIR)/depend.dir/*.mk)
include $(PROJECT_MODULE_MAKEFILES)
endif
include $(MAKE_CONFIG_DIR)/config
ifneq ($(wildcard $(MAKE_CONFIG_DIR)/super),)
include $(MAKE_CONFIG_DIR)/super
endif
ifneq ($(wildcard $(MAKE_CONFIG_DIR)/third),)
include $(MAKE_CONFIG_DIR)/third
endif
include $(MAKE_CONFIG_DIR)/target

# ** Project Settings **
#
#    Output Name
#    TARGET_NAME     =  : Defined in .make/config and also can be redefine here.

# Path where headers to be installed.
ifdef ROOT_HEADER_INSTALL_PATH
    HEADER_INSTALL_PATH = ${ROOT_HEADER_INSTALL_PATH}
    CCFLAGS += -I${ROOT_HEADER_INSTALL_PATH}
    PPFLAGS += -I${ROOT_HEADER_INSTALL_PATH}
endif

# Path where outputed binary to be installed.
ifdef ROOT_BINARY_INSTALL_PATH
    BINARY_INSTALL_PATH  = ${ROOT_BINARY_INSTALL_PATH}
endif

# Path where outputed library to be installed.
ifdef ROOT_LIBRARY_INSTALL_PATH
    LIBRARY_INSTALL_PATH  = ${ROOT_LIBRARY_INSTALL_PATH}
	LDFLAGS += -L${ROOT_LIBRARY_INSTALL_PATH}
    LDFLAGS += -Wl,-rpath=${ROOT_LIBRARY_INSTALL_PATH}
endif

# Path where aplications depended by this project to be downloaded.
ifdef ROOT_DEPENDS_APPLICATION_PATH
    DEPENDS_APPLICATION_PATH  = ${ROOT_DEPENDS_APPLICATION_PATH}
endif

# Path where libraries depended by this project to be downloaded.
ifdef ROOT_DEPENDS_LIBRARY_PATH
    DEPENDS_LIBRARY_PATH  = ${ROOT_DEPENDS_LIBRARY_PATH}
endif

# Path where third-parties depended by this project to be downloaded.
ifdef ROOT_DEPENDS_THIRD_PATH
    DEPENDS_THIRD_PATH  = ${ROOT_DEPENDS_THIRD_PATH}
endif

ifndef ROOT_HEADER_INSTALL_PATH
export ROOT_HEADER_INSTALL_PATH  = ${HEADER_INSTALL_PATH}
endif
ifndef ROOT_BINARY_INSTALL_PATH
export ROOT_BINARY_INSTALL_PATH  = ${BINARY_INSTALL_PATH}
endif
ifndef ROOT_LIBRARY_INSTALL_PATH
export ROOT_LIBRARY_INSTALL_PATH = ${LIBRARY_INSTALL_PATH}
endif
ifndef ROOT_DEPENDS_APPLICATION_PATH
export ROOT_DEPENDS_APPLICATION_PATH = ${DEPENDS_APPLICATION_PATH}
endif
ifndef ROOT_DEPENDS_LIBRARY_PATH
export ROOT_DEPENDS_LIBRARY_PATH = ${DEPENDS_LIBRARY_PATH}
endif
ifndef ROOT_DEPENDS_THIRD_PATH
export ROOT_DEPENDS_THIRD_PATH  = ${DEPENDS_THIRD_PATH}
endif

include $(MAKE_CONFIG_DIR)/prepare
include $(MAKE_CONFIG_DIR)/install

ifdef ROOT_INCLUDE_PATH
    CCFLAGS += -I${ROOT_INCLUDE_PATH}
	PPFLAGS += -I${ROOT_INCLUDE_PATH}
endif
ifdef ROOT_LIBRARY_PATH
    LDFLAGS += -L${ROOT_LIBRARY_PATH}
endif
ifdef ROOT_RUNTIME_PATH
    LDFLAGS += -Wl,-rpath=${ROOT_RUNTIME_PATH}
endif

TARGET_BIN_DIR := ./bin
TARGET_LIB_DIR := ./lib

ifdef CONFIG_HEADER_SEARCH_DIRS
ifneq (${CONFIG_HEADER_SEARCH_DIRS},)
HEADER_SEARCH_DIRS += ${CONFIG_HEADER_SEARCH_DIRS}
endif
endif

ifdef TARGET_HEADER_SEARCH_DIRS
ifneq (${TARGET_HEADER_SEARCH_DIRS},)
HEADER_SEARCH_DIRS += ${TARGET_HEADER_SEARCH_DIRS}
endif
endif

ifdef CONFIG_LIBRARY_SEARCH_DIRS
ifneq (${CONFIG_LIBRARY_SEARCH_DIRS},)
LIBRARY_SEARCH_DIRS += ${CONFIG_LIBRARY_SEARCH_DIRS}
endif
endif

ifdef TARGET_LIBRARY_SEARCH_DIRS
ifneq (${TARGET_LIBRARY_SEARCH_DIRS},)
LIBRARY_SEARCH_DIRS += ${TARGET_LIBRARY_SEARCH_DIRS}
endif
endif

# Flags
ASFLAGS += ${TARGET_FLAGS_AS} ${CONFIG_FLAGS_AS}
CCFLAGS += ${TARGET_FLAGS_CC} ${CONFIG_FLAGS_CC} ${HEADER_SEARCH_DIRS}
PPFLAGS += ${TARGET_FLAGS_PP} ${CONFIG_FLAGS_PP} ${HEADER_SEARCH_DIRS}
ARFLAGS += ${TARGET_FLAGS_AR} ${CONFIG_FLAGS_AR}
LDFLAGS += ${TARGET_FLAGS_LD} ${CONFIG_FLAGS_LD} ${LIBRARY_SEARCH_DIRS}

ifdef CONFIG_SOURCE_ROOT_DIRS
ifneq (${CONFIG_SOURCE_ROOT_DIRS},)
SOURCE_ROOT_DIRS += ${CONFIG_SOURCE_ROOT_DIRS}
endif
endif
ifdef TARGET_SOURCE_ROOT_DIRS
ifneq (${TARGET_SOURCE_ROOT_DIRS},)
SOURCE_ROOT_DIRS +=${TARGET_SOURCE_ROOT_DIRS}
endif
endif
SOURCE_DIRS   = $(shell find $(SOURCE_ROOT_DIRS) $(SOURCE_DIR_BESIDES) -prune -o -type d -print)

TARGET_HEADERS = $(foreach dir,$(SOURCE_DIRS),$(wildcard $(dir)/*.h))

TARGET_SOURCES_AS  += $(foreach dir,$(SOURCE_DIRS),$(wildcard $(dir)/*.s))
TARGET_OBJECTS_AS  += $(patsubst %.s,%.o,$(TARGET_SOURCES_AS))
TARGET_SOURCES_CC  += $(foreach dir,$(SOURCE_DIRS),$(wildcard $(dir)/*.c))
TARGET_OBJECTS_CC  += $(patsubst %.c,%.o,$(TARGET_SOURCES_CC))
TARGET_SOURCES_PP  += $(foreach dir,$(SOURCE_DIRS),$(wildcard $(dir)/*.cpp))
TARGET_OBJECTS_PP  += $(patsubst %.cpp,%.o,$(TARGET_SOURCES_PP))

TARGET_HEADER_DIRS += $(foreach dir,$(SOURCE_DIRS),-I$(dir))

# libraries to be linked with.[NOTICE: also defined in .make/config]
TARGET_LIBS += ${TARGET_LINK_WITH_LIBS} ${CONFIG_LINK_WITH_LIBS} 

ifeq ($(TARGET_TYPE_LIB),$(MK_TRUE))
TARGETS += ${TARGET_LIB_DIR}/${TARGET_NAME}${TARGET_LIB_EXT_STATIC}
endif
ifeq ($(TARGET_TYPE_DLL),$(MK_TRUE))
TARGETS += ${TARGET_LIB_DIR}/${TARGET_NAME}${TARGET_LIB_EXT_DYNAMIC}
endif
ifeq ($(TARGET_TYPE_BIN),$(MK_TRUE))
TARGETS += ${TARGET_BIN_DIR}/${TARGET_NAME}${TARGET_BIN_EXT}
endif

ifdef THIRD_TARGETS
ALL : THIRD_TARGETS $(TARGETS)
recursive:$(DEPEND_TARGETS) THIRD_TARGETS $(TARGETS)
else 
ALL : $(TARGETS)
recursive:$(DEPEND_TARGETS) $(TARGETS)
endif

${TARGET_LIB_DIR}/${TARGET_NAME}${TARGET_LIB_EXT_STATIC}:$(TARGET_OBJECTS_PP) $(TARGET_OBJECTS_CC) $(TARGET_OBJECTS_AS)
	$(AR) -crs $@ $^

${TARGET_LIB_DIR}/${TARGET_NAME}${TARGET_LIB_EXT_DYNAMIC}:$(TARGET_OBJECTS_PP) $(TARGET_OBJECTS_CC) $(TARGET_OBJECTS_AS)
	$(CC) -fPIC -shared -o $@ $^ ${LDFLAGS} $(TARGET_LIBS)

${TARGET_BIN_DIR}/${TARGET_NAME}${TARGET_BIN_EXT}: $(TARGET_OBJECTS_PP) $(TARGET_OBJECTS_CC) $(TARGET_OBJECTS_AS)
	$(CC) -o $@ $^ ${LDFLAGS} $(TARGET_LIBS) 

$(TARGET_OBJECTS_AS):%.o:%.s
	$(AS) ${ASFLAGS} $< -o $@
$(TARGET_OBJECTS_CC):%.o:%.c
	$(CC) ${CCFLAGS} $< -o $@ 
$(TARGET_OBJECTS_PP):%.o:%.cpp
	$(PP) ${PPFLAGS} $< -o $@

clean   :
	rm -f $(TARGET_OBJECTS_AS)
	rm -f $(TARGET_OBJECTS_CC)
	rm -f $(TARGET_OBJECTS_PP)
	rm -f ${TARGET_LIB_DIR}/${TARGET_NAME}*
	rm -f ${TARGET_BIN_DIR}/${TARGET_NAME}${TARGET_BIN_EXT}
prepare:$(PREPARE_TARGETS)
ifdef SUPER_MAKE_CONFIG_DIR
ifdef ROOT_MAKE_CONFIG_DIR
ifeq (${SUPER_MAKE_CONFIG_DIR},${ROOT_MAKE_CONFIG_DIR})
	-rm $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
#prepare 1
	@echo "DEPEND_TARGETS  += $(TARGET_NAME).recursive"                                       >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "UPDATE_TARGETS  += $(TARGET_NAME).update"                                          >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "PUBLISH_TARGETS += $(TARGET_NAME).publish"                                         >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "ECHO_TARGETS    += $(TARGET_NAME).echo"                                            >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "$(TARGET_NAME):"                                                                   >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "	@echo SUPER_MAKE_DIR=${ROOT_MAKE_DIR}                >> ${MAKE_CONFIG_DIR}/super" >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "	@echo SUPER_MAKE_CONFIG_DIR=${ROOT_MAKE_CONFIG_DIR}  >> $(MAKE_CONFIG_DIR)/super" >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "	cd $(MAKE_FILE_DIR) && $(MAKE) && $(MAKE) install"                                >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "	-rm $(MAKE_CONFIG_DIR)/super"                                                     >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "$(TARGET_NAME).recursive:"                                                         >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "	@echo SUPER_MAKE_DIR=${SUPER_MAKE_DIR}               >> ${MAKE_CONFIG_DIR}/super" >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "	@echo SUPER_MAKE_CONFIG_DIR=${SUPER_MAKE_CONFIG_DIR} >> $(MAKE_CONFIG_DIR)/super" >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "	cd $(MAKE_FILE_DIR) && $(MAKE) recursive && $(MAKE) install"                      >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "	-rm $(MAKE_CONFIG_DIR)/super"                                                     >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "$(TARGET_NAME).clean:"                                                             >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "	@echo SUPER_MAKE_DIR=${ROOT_MAKE_DIR}               >> ${MAKE_CONFIG_DIR}/super"  >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "	@echo SUPER_MAKE_CONFIG_DIR=${ROOT_MAKE_CONFIG_DIR} >> $(MAKE_CONFIG_DIR)/super"  >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "	cd $(MAKE_FILE_DIR) && $(MAKE) clean"                                             >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "	-rm $(MAKE_CONFIG_DIR)/super"                                                     >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "$(TARGET_NAME).prepare:"                                                           >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "	@echo SUPER_MAKE_DIR=${ROOT_MAKE_DIR}               >> ${MAKE_CONFIG_DIR}/super"  >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "	@echo SUPER_MAKE_CONFIG_DIR=${ROOT_MAKE_CONFIG_DIR} >> $(MAKE_CONFIG_DIR)/super"  >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "	cd $(MAKE_FILE_DIR) && $(MAKE) prepare"                                           >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "	-rm $(MAKE_CONFIG_DIR)/super"                                                     >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "$(TARGET_NAME).install:"                                                           >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "	@echo SUPER_MAKE_DIR=${ROOT_MAKE_DIR}               >> ${MAKE_CONFIG_DIR}/super"  >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "	@echo SUPER_MAKE_CONFIG_DIR=${ROOT_MAKE_CONFIG_DIR} >> $(MAKE_CONFIG_DIR)/super"  >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "	cd $(MAKE_FILE_DIR) && $(MAKE) install"                                           >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "	-rm $(MAKE_CONFIG_DIR)/super"                                                     >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "$(TARGET_NAME).uninstall:"                                                         >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "	@echo SUPER_MAKE_DIR=${ROOT_MAKE_DIR}               >> ${MAKE_CONFIG_DIR}/super"  >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "	@echo SUPER_MAKE_CONFIG_DIR=${ROOT_MAKE_CONFIG_DIR} >> $(MAKE_CONFIG_DIR)/super"  >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "	cd $(MAKE_FILE_DIR) && $(MAKE) uninstall"                                         >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "	-rm $(MAKE_CONFIG_DIR)/super"                                                     >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "$(TARGET_NAME).publish:"                                                           >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "	@echo SUPER_MAKE_DIR=${ROOT_MAKE_DIR}               >> ${MAKE_CONFIG_DIR}/super"  >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "	@echo SUPER_MAKE_CONFIG_DIR=${ROOT_MAKE_CONFIG_DIR} >> $(MAKE_CONFIG_DIR)/super"  >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "	cd $(MAKE_FILE_DIR) && $(MAKE) publish"                                           >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "	-rm $(MAKE_CONFIG_DIR)/super"                                                     >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "$(TARGET_NAME).update:"                                                            >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "	@echo SUPER_MAKE_DIR=${ROOT_MAKE_DIR}               >> ${MAKE_CONFIG_DIR}/super"  >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "	@echo SUPER_MAKE_CONFIG_DIR=${ROOT_MAKE_CONFIG_DIR} >> $(MAKE_CONFIG_DIR)/super"  >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "	cd $(MAKE_FILE_DIR) && $(MAKE) update"                                            >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "	-rm $(MAKE_CONFIG_DIR)/super"                                                     >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "$(TARGET_NAME).echo:"                                                              >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "	@echo SUPER_MAKE_DIR=${ROOT_MAKE_DIR}               >> ${MAKE_CONFIG_DIR}/super"  >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "	@echo SUPER_MAKE_CONFIG_DIR=${ROOT_MAKE_CONFIG_DIR} >> $(MAKE_CONFIG_DIR)/super"  >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "	cd $(MAKE_FILE_DIR) && $(MAKE) echo"                                              >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "	-rm $(MAKE_CONFIG_DIR)/super"                                                     >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
endif
ifneq (${SUPER_MAKE_CONFIG_DIR},${ROOT_MAKE_CONFIG_DIR})
#prepare.2
	-rm $(SUPER_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "DEPEND_TARGETS += $(TARGET_NAME).recursive"                                        >> $(SUPER_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "ECHO_TARGETS += $(TARGET_NAME).echo"                                               >> $(SUPER_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "$(TARGET_NAME).recursive:"                                                         >> $(SUPER_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "	@echo SUPER_MAKE_DIR=${SUPER_MAKE_DIR}               >> ${MAKE_CONFIG_DIR}/super" >> $(SUPER_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "	@echo SUPER_MAKE_CONFIG_DIR=${SUPER_MAKE_CONFIG_DIR} >> $(MAKE_CONFIG_DIR)/super" >> $(SUPER_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "	cd $(MAKE_FILE_DIR) && $(MAKE) recursive && $(MAKE) install"                      >> $(SUPER_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "	-rm $(MAKE_CONFIG_DIR)/super"                                                     >> $(SUPER_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "$(TARGET_NAME).echo:"                                                              >> $(SUPER_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "	@echo SUPER_MAKE_DIR=${SUPER_MAKE_DIR}               >> ${MAKE_CONFIG_DIR}/super" >> $(SUPER_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "	@echo SUPER_MAKE_CONFIG_DIR=${SUPER_MAKE_CONFIG_DIR} >> $(MAKE_CONFIG_DIR)/super" >> $(SUPER_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "	cd $(MAKE_FILE_DIR) && $(MAKE) echo"                                              >> $(SUPER_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "	-rm $(MAKE_CONFIG_DIR)/super"                                                     >> $(SUPER_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
ifeq ($(wildcard $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk),)
#prepare.3
	@echo "DEPEND_TARGETS  += $(TARGET_NAME).recursive"                                       >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "ECHO_TARGETS    += $(TARGET_NAME).echo"                                            >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "$(TARGET_NAME):"                                                                   >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "	@echo SUPER_MAKE_DIR=${ROOT_MAKE_DIR}                >> ${MAKE_CONFIG_DIR}/super" >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "	@echo SUPER_MAKE_CONFIG_DIR=${ROOT_MAKE_CONFIG_DIR}  >> $(MAKE_CONFIG_DIR)/super" >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "	cd $(MAKE_FILE_DIR) && $(MAKE) && $(MAKE) install"                                >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "	-rm $(MAKE_CONFIG_DIR)/super"                                                     >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "$(TARGET_NAME).recursive:"                                                         >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "	@echo SUPER_MAKE_DIR=${SUPER_MAKE_DIR}               >> ${MAKE_CONFIG_DIR}/super" >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "	@echo SUPER_MAKE_CONFIG_DIR=${SUPER_MAKE_CONFIG_DIR} >> $(MAKE_CONFIG_DIR)/super" >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "	cd $(MAKE_FILE_DIR) && $(MAKE) recursive && $(MAKE) install"                      >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "	-rm $(MAKE_CONFIG_DIR)/super"                                                     >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "$(TARGET_NAME).clean:"                                                             >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "	@echo SUPER_MAKE_DIR=${ROOT_MAKE_DIR}               >> ${MAKE_CONFIG_DIR}/super"  >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "	@echo SUPER_MAKE_CONFIG_DIR=${ROOT_MAKE_CONFIG_DIR} >> $(MAKE_CONFIG_DIR)/super"  >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "	cd $(MAKE_FILE_DIR) && $(MAKE) clean"                                             >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "	-rm $(MAKE_CONFIG_DIR)/super"                                                     >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "$(TARGET_NAME).prepare:"                                                           >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "	@echo SUPER_MAKE_DIR=${ROOT_MAKE_DIR}               >> ${MAKE_CONFIG_DIR}/super"  >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "	@echo SUPER_MAKE_CONFIG_DIR=${ROOT_MAKE_CONFIG_DIR} >> $(MAKE_CONFIG_DIR)/super"  >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "	cd $(MAKE_FILE_DIR) && $(MAKE) prepare"                                           >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "	-rm $(MAKE_CONFIG_DIR)/super"                                                     >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "$(TARGET_NAME).install:"                                                           >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "	@echo SUPER_MAKE_DIR=${ROOT_MAKE_DIR}               >> ${MAKE_CONFIG_DIR}/super"  >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "	@echo SUPER_MAKE_CONFIG_DIR=${ROOT_MAKE_CONFIG_DIR} >> $(MAKE_CONFIG_DIR)/super"  >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "	cd $(MAKE_FILE_DIR) && $(MAKE) install"                                           >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "	-rm $(MAKE_CONFIG_DIR)/super"                                                     >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "$(TARGET_NAME).uninstall:"                                                         >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "	@echo SUPER_MAKE_DIR=${ROOT_MAKE_DIR}               >> ${MAKE_CONFIG_DIR}/super"  >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "	@echo SUPER_MAKE_CONFIG_DIR=${ROOT_MAKE_CONFIG_DIR} >> $(MAKE_CONFIG_DIR)/super"  >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "	cd $(MAKE_FILE_DIR) && $(MAKE) uninstall"                                         >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "	-rm $(MAKE_CONFIG_DIR)/super"                                                     >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "$(TARGET_NAME).publish:"                                                           >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "	@echo SUPER_MAKE_DIR=${ROOT_MAKE_DIR}               >> ${MAKE_CONFIG_DIR}/super"  >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "	@echo SUPER_MAKE_CONFIG_DIR=${ROOT_MAKE_CONFIG_DIR} >> $(MAKE_CONFIG_DIR)/super"  >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "	cd $(MAKE_FILE_DIR) && $(MAKE) publish"                                           >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "	-rm $(MAKE_CONFIG_DIR)/super"                                                     >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "$(TARGET_NAME).update:"                                                            >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "	@echo SUPER_MAKE_DIR=${ROOT_MAKE_DIR}               >> ${MAKE_CONFIG_DIR}/super"  >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "	@echo SUPER_MAKE_CONFIG_DIR=${ROOT_MAKE_CONFIG_DIR} >> $(MAKE_CONFIG_DIR)/super"  >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "	cd $(MAKE_FILE_DIR) && $(MAKE) update"                                            >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "	-rm $(MAKE_CONFIG_DIR)/super"                                                     >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "$(TARGET_NAME).echo:"                                                              >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "	@echo SUPER_MAKE_DIR=${ROOT_MAKE_DIR}               >> ${MAKE_CONFIG_DIR}/super"  >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "	@echo SUPER_MAKE_CONFIG_DIR=${ROOT_MAKE_CONFIG_DIR} >> $(MAKE_CONFIG_DIR)/super"  >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "	cd $(MAKE_FILE_DIR) && $(MAKE) echo"                                              >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
	@echo "	-rm $(MAKE_CONFIG_DIR)/super"                                                     >> $(ROOT_MAKE_CONFIG_DIR)/depend.dir/$(TARGET_NAME).mk
endif
endif
endif
endif
ifndef ROOT_MAKE_CONFIG_DIR
	@echo "no ROOT_MAKE_CONFIG_DIR found."
endif
install :${INSTALL_TARGETS}
	@echo ${TARGET_NAME} : Installed.
uninstall : 
ifneq ($(wildcard $(HEADER_INSTALL_PATH)),)
	-rm -rf $(HEADER_INSTALL_PATH)/$(TARGET_NAME)
else
	@echo "install : no HEADER_INSTALL_PATH found"
endif
ifneq ($(wildcard $(BINARY_INSTALL_PATH)),)
	-rm -rf $(BINARY_INSTALL_PATH)/$(TARGET_NAME)${TARGET_BIN_EXT}
else
	@echo "install : no BINARY_INSTALL_PATH found"
endif
ifneq ($(wildcard $(LIBRARY_INSTALL_PATH)),)
	-rm -rf $(LIBRARY_INSTALL_PATH)/$(TARGET_NAME)*
else
	@echo "install : no LIBRARY_INSTALL_PATH found"
endif
publish:$(PUBLISH_TARGETS)
	-git add . && git commit -m "$(shell date)" && git push
update:$(UPDATE_TARGETS)
	-git pull
echo: #$(ECHO_TARGETS)
	@echo TARGET_NAME:$(TARGET_NAME)
ifdef REMOTE_ALL_IN_ONE
	@echo REMOTE_ALL_IN_ONE Defined
endif
	@echo HEADER_SEARCH_DIRS:${HEADER_SEARCH_DIRS}
	@echo CONFIG_HEADER_SEARCH_DIRS:${CONFIG_HEADER_SEARCH_DIRS}
	@echo TARGET_HEADER_SEARCH_DIRS:${TARGET_HEADER_SEARCH_DIRS}
	@echo HEADER_INSTALL_PATH:$(HEADER_INSTALL_PATH)
	@echo BINARY_INSTALL_PATH:$(BINARY_INSTALL_PATH)
	@echo LIBRARY_INSTALL_PATH:$(LIBRARY_INSTALL_PATH)
	@echo DEPENDS_LIBRARY_PATH:$(DEPENDS_LIBRARY_PATH)
	@echo DEPENDS_THIRD_PATH:$(DEPENDS_THIRD_PATH)
	@echo SUPER_MAKE_DIR:$(SUPER_MAKE_DIR)
	@echo SUPER_MAKE_CONFIG_DIR:$(SUPER_MAKE_CONFIG_DIR)
	@echo ROOT_MAKE_DIR:${ROOT_MAKE_DIR}
	@echo ROOT_MAKE_CONFIG_DIR:${ROOT_MAKE_CONFIG_DIR}
	@echo TOOLCHAIN_AS:${AS}
	@echo TOOLCHAIN_CC:${CC}
	@echo TOOLCHAIN_PP:${PP}
	@echo TOOLCHAIN_AR:${AR}
	@echo TOOLCHAIN_LD:${LD}
	@echo ASFLAGS:${ASFLAGS}
	@echo CCFLAGS:${CCFLAGS}
	@echo PPFLAGS:${PPFLAGS}
#	@echo ARFLAGS:${ARFLAGS}
	@echo LDFLAGS:${LDFLAGS}
