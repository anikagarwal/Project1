cmake_minimum_required(VERSION 3.8)
project(Project1)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        american-english
        american-english.txt
        bobsledding.txt
        CMakeLists.txt
        GRADE_REPORT.txt
        greek-finances.txt
        header.c
        main.cpp
        Makefile
        proj1_output_duplicates.txt
        proj1_output_noduplicates.txt
        Project1.cpp)

add_executable(Project1 ${SOURCE_FILES})