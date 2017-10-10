cmake_minimum_required(VERSION 3.8)
project(CS304)
add_custom_target(cleancache
        COMMAND make clean
        WORKING_DIRECTORY ${CS304_SOURCE_DIR}/CS304-A3-mkem114-6273632/task_1)
add_custom_target(cleanmatrix
        COMMAND make clean
        WORKING_DIRECTORY ${CS304_SOURCE_DIR}/CS304-A3-mkem114-6273632/task_2)
add_custom_target(buildcache
        COMMAND make
        WORKING_DIRECTORY ${CS304_SOURCE_DIR}/CS304-A3-mkem114-6273632/task_1)
add_custom_target(buildmatrix
        COMMAND make
        WORKING_DIRECTORY ${CS304_SOURCE_DIR}/CS304-A3-mkem114-6273632/task_2)