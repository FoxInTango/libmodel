# make target=...

${Makefile_VAR} = ${CONFIG_VAR} + ${TARGET_VAR} as Blow:
# 1, .make/config 
    Makefile : TARGET[MAIN]_LIBS     += .make/config : CONFIG_LIBS
    Makefile : TARGET[MAIN]_AS_FLAGS += .make/config : CONFIG_AS_FLAGS
    Makefile : TARGET[MAIN]_CC_FLAGS += .make/config : CONFIG_CC_FLAGS
    Makefile : TARGET[MAIN]_PP_FLAGS += .make/config : CONFIG_PP_FLAGS
    Makefile : TARGET[MAIN]_LD_FLAGS += .make/config : CONFIG_LD_FLAGS
    Makefile : TARGET[MAIN]_HEADER_SEARCH_PATH += .make/config : CONFIG_HEADER_SEARCH_PATH
# 2, .make/targets/target
    Makefile : TARGET[MAIN]_LIBS     += .make/targets/target : TARGET_LIBS
    Makefile : TARGET[MAIN]_AS_FLAGS += .make/targets/target : TARGET_AS_FLAGS
    Makefile : TARGET[MAIN]_CC_FLAGS += .make/targets/target : TARGET_CC_FLAGS
    Makefile : TARGET[MAIN]_PP_FLAGS += .make/targets/target : TARGET_PP_FLAGS
    Makefile : TARGET[MAIN]_LD_FLAGS += .make/targets/target : TARGET_LD_FLAGS
    Makefile : TARGET[MAIN]_HEADER_SEARCH_PATH += .make/targets/target : TARGET_HEADER_SEARCH_PATH
    target name extesions .so .a ..

# 3,third party