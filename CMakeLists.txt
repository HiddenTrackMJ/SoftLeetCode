﻿# CMakeList.txt : CMake project for SoftLeetCode, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("SoftLeetCode" VERSION 0.0.1)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)
#set(CMAKE_CXX_FLAGS "-D__STDC_CONSTANT_MACROS")

if(MSVC)
	SET(CMAKE_CXX_FLAGS "/EHsc")  # deal with MSVC Warning C4530, mac
    SET(CMAKE_CXX_FLAGS "/utf-8" "${CMAKE_CXX_FLAGS}")    # for CPP
    SET(CMAKE_C_FLAGS "/utf-8" "${CMAKE_C_FLAGS}")        # for C
else()
	set(CMAKE_CXX_FLAGS "-D__STDC_CONSTANT_MACROS")
endif()


# Add source to this project's executable.
aux_source_directory(./src CPPLIST)

file(GLOB HEADERS
        ${CMAKE_CURRENT_LIST_DIR}/include/*.h
        )
message(STATUS "HEADERS: " ${HEADERS})



add_executable(${PROJECT_NAME}
        "./src/leet_1.cpp"
        "./src/dynamic.cpp"
        "./src/SoftLeetCode.cpp"
        ${HEADERS}
         "src/leet_2.cpp")

target_include_directories(${PROJECT_NAME}
        PRIVATE
        ${PROJECT_SOURCE_DIR}/include
        ${HEADERS}
        )

target_link_libraries( ${PROJECT_NAME}  
	    PRIVATE 
)

add_executable( jian
        "./src/jian_1.cpp"
        "./src/jian_main.cpp"
        ${HEADERS}
         "src/leet_2.cpp")

target_include_directories( jian
        PRIVATE
        ${PROJECT_SOURCE_DIR}/include
        )

target_link_libraries( jian
	    PRIVATE 
)

add_executable( test
        "./src/jian_1.cpp"
        "./src/test.cpp"
        ${HEADERS}
         "src/leet_2.cpp")

target_include_directories( test
        PRIVATE
        ${PROJECT_SOURCE_DIR}/include
        )

target_link_libraries( jian
	    PRIVATE 
)
