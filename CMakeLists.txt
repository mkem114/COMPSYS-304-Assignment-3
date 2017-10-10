cmake_minimum_required(VERSION 3.8)
project(CS304)

add_custom_target(cachetest1 COMMAND make -C ${cachetest1_SOURCE_DIR}
        CLION_EXE_DIR=${PROJECT_BINARY_DIR})

set(SOURCE_FILES cachetest1.c)

add_executable(CS304A3 ${SOURCE_FILES})