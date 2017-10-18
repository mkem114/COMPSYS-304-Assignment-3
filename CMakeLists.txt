cmake_minimum_required(VERSION 3.8)
project(CS304)
add_custom_target(cleancache
        COMMAND make clean
        WORKING_DIRECTORY ${CS304_SOURCE_DIR}/CS304-A3-mkem114-6273632/task_1)
add_custom_target(cleanmatrix
        COMMAND make clean
        WORKING_DIRECTORY ${CS304_SOURCE_DIR}/CS304-A3-mkem114-6273632/task_2)
add_custom_target(cleantex
        COMMAND rm -f assignment3_answer.aux assignment3_answer.log assignment3_answer.synctex.gz
        WORKING_DIRECTORY ${CS304_SOURCE_DIR})
add_custom_target(buildcache
        COMMAND make
        WORKING_DIRECTORY ${CS304_SOURCE_DIR}/CS304-A3-mkem114-6273632/task_1)
add_custom_target(buildmatrix
        COMMAND make
        WORKING_DIRECTORY ${CS304_SOURCE_DIR}/CS304-A3-mkem114-6273632/task_2)

set(SOURCE_FILES
        CS304-A3-mkem114-6273632/task_1/cachetest1.c
        CS304-A3-mkem114-6273632/task_1/cachetest2.c
        CS304-A3-mkem114-6273632/task_2/matrix1.c
        CS304-A3-mkem114-6273632/task_2/matrix2.c
        CS304-A3-mkem114-6273632/task_2/matrix3.c)

add_executable(dummy ${SOURCE_FILES})
add_executable(BLANK .gitignore)
