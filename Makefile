cc=clang

PLATFORM_ARCH         = $(shell uname -s)
PLATFORM_ARCH_LINUX   = Linux
PLATFORM_ARCH_DARWIN  = Darwin
PLATFORM_ARCH_FREEBSD = FreeBSD

# 输出类型配置
TARGET_TYPE_BIN = BINARY
TARGET_TYPE_LIB = STATIC
TARGET_TYPE_DLL = SHARED

# ** 项目配置区 **
#    输出文件名称
TARGET_NAME     = libmodule
#    输出文件类型
TARGET_TYPE     = ${TARGET_TYPE_DLL}
#    输出文件后缀 [自动判别]
TARGET_NAME_EXT =
#    安装位置
INSTALL_PATH    = /usr/local/libmodule

TARGET_OBJECTS_DIR := ./out
TARGET_HEADERS_DIR := ./include
TARGET_SOURCES_DIR := ./source
TARGET_BINARY_DIR  := ./bin
TARGET_LIBRARY_DIR := ./lib

TARGET_SOURCES = $(wildcard ${TARGET_SOURCES_DIR}/*.cpp)
TARGET_OBJECTS = $(patsubst %.cpp,${TARGET_OBJECTS_DIR}/%.o,$(notdir ${TARGET_SOURCES}))
TARGET_HEADERS = $(wildcard $(TARGET_HEADERS_DIR)/*.h)

TARGET_LIBS = -lstdc++ -ldl
# 链接标志
TARGET_LIB_PIC_SHARED  = -fPIC
TARGET_LIB_PIC_STATIC  = 
TARGET_LIB_PIC_BINARY  = -fPIE
TARGET_LIB_FLAG_SHARED = -shared
TARGET_LIB_FLAG_STATIC =
# 自动判别
TARGET_LIB_PIC  = 
TARGET_LIB_FLAG = 

CFLAGS   = -Wall -fvisibility=hidden -I${TARGET_HEADERS_DIR} -I${THIRDS_HEADERS_DIR}
CXXFLAGS = -std=c++11 

# 平台检测 -- DARWIN
ifeq (${PLATFORM_ARCH},${PLATFORM_ARCH_DARWIN})
   ifeq (${TARGET_TYPE},${TARGET_TYPE_BIN})
       TARGET_LIB_FLAG :=
       TARGET_LIB_PIC  := ${TARGET_LIB_PIC_BINARY}
       TARGET_LD_FLAGS += 
       TARGET_NAME_EXT := 
       TARGET_NAME     := ${TARGET_NAME}.${TARGET_NAME_EXT}
   endif
   ifeq (${TARGET_TYPE},${TARGET_TYPE_LIB})
       TARGET_LIB_FLAG :=
       TARGET_LIB_PIC  := ${TARGET_LIB_PIC_STATIC}
       TARGET_LD_FLAGS += 
       TARGET_NAME_EXT := a
       TARGET_NAME     := ${TARGET_NAME}.${TARGET_NAME_EXT}
   endif
   ifeq (${TARGET_TYPE},${TARGET_TYPE_DLL})
       TARGET_LIB_FLAG := ${TARGET_LIB_FLAG_SHARED}
       TARGET_LIB_PIC  := ${TARGET_LIB_PIC_SHARED}
       TARGET_LD_FLAGS += -dynamiclib
       TARGET_NAME_EXT := dylib
       TARGET_NAME     := ${TARGET_NAME}.${TARGET_NAME_EXT}
   endif
endif
# 平台检测 -- LINUX
ifeq (${PLATFORM_ARCH},${PLATFORM_ARCH_LINUX})
   ifeq (${TARGET_TYPE},${TARGET_TYPE_BIN})
       TARGET_LIB_FLAG :=
       TARGET_LIB_PIC  := ${TARGET_LIB_PIC_BINARY}
       TARGET_LD_FLAGS +=
       TARGET_NAME_EXT :=
       TARGET_NAME     := ${TARGET_NAME}.${TARGET_NAME_EXT}
   endif
   ifeq (${TARGET_TYPE},${TARGET_TYPE_LIB})
       TARGET_LIB_FLAG :=
       TARGET_LIB_PIC  := ${TARGET_LIB_PIC_STATIC}
       TARGET_LD_FLAGS +=
       TARGET_NAME_EXT := a
       TARGET_NAME     := ${TARGET_NAME}.${TARGET_NAME_EXT}
   endif
   ifeq (${TARGET_TYPE},${TARGET_TYPE_DLL})
       TARGET_LIB_FLAG := ${TARGET_LIB_FLAG_SHARED}
       TARGET_LIB_PIC  := ${TARGET_LIB_PIC_SHARED}
       TARGET_LD_FLAGS += 
       TARGET_NAME_EXT := so
       TARGET_NAME     := ${TARGET_NAME}.${TARGET_NAME_EXT}
   endif
endif

# 平台检测 -- FreeBSD
ifeq (${PLATFORM_ARCH},${PLATFORM_ARCH_FreeBSD})
   ifeq (${TARGET_TYPE},${TARGET_TYPE_BIN})
       TARGET_LIB_FLAG :=
       TARGET_LIB_PIC  := ${TARGET_LIB_PIC_BINARY}
       TARGET_LD_FLAGS +=
       TARGET_NAME_EXT :=
       TARGET_NAME     := ${TARGET_NAME}.${TARGET_NAME_EXT}
   endif
   ifeq (${TARGET_TYPE},${TARGET_TYPE_LIB})
       TARGET_LIB_FLAG :=
       TARGET_LIB_PIC  := ${TARGET_LIB_PIC_STATIC}
       TARGET_LD_FLAGS +=
       TARGET_NAME_EXT := a
       TARGET_NAME     := ${TARGET_NAME}.${TARGET_NAME_EXT}
   endif
   ifeq (${TARGET_TYPE},${TARGET_TYPE_DLL})
       TARGET_LIB_FLAG := ${TARGET_LIB_FLAG_SHARED}
       TARGET_LIB_PIC  := ${TARGET_LIB_PIC_SHARED}
       TARGET_LD_FLAGS += 
       TARGET_NAME_EXT := so
       TARGET_NAME     := ${TARGET_NAME}.${TARGET_NAME_EXT}
   endif
endif

${TARGET_LIBRARY_DIR}/${TARGET_NAME} : $(TARGET_OBJECTS) $(THIRDS_OBJECTS)
	cc ${TARGET_LD_FLAGS} ${TARGET_LIB_PIC} ${TARGET_LIB_FLAG} -o $@ $(TARGET_OBJECTS) ${TARGET_LIBS}
 
${TARGET_OBJECTS_DIR}/%.o : $(TARGET_SOURCES_DIR)/%.cpp
	cc ${CFLAGS} ${CXXFLAGS} -c $< -o $@ ${TARGET_LIB_PIC}

module: ./out/main.o
	cc -o bin/arguments ./out/main.o -lmodule ${TARGET_LIBS}
./out/main.o:./main/main.cpp
	cc ${CFLAGS} ${CXXFLAGS} -c ./main/main.cpp -o ./out/main.o
clean   :
	rm ${TARGET_OBJECTS_DIR}/*.o
	rm ${TARGET_LIBRARY_DIR}/*.${TARGET_NAME_EXT}
install :
	rm -rf /usr/local/include/libmodule
	mkdir  /usr/local/include/libmodule
	cp  -rf ./include/* /usr/local/include/libmodule
	cp  -rf ./lib/${TARGET_NAME}  /usr/local/lib
uninstall : 
	rm -rf /usr/local/include/libmodule
	rm -rf /usr/local/lib/${TARGET_NAME}
