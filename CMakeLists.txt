cmake_minimum_required(VERSION 3.10.2)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

project(advent-of-code-2021 CXX)
SET (INCLUDE_DIR ./common)
SET (SOURCE_DIR ./src)

file(GLOB SRC_FILES ${SOURCE_DIR}/*.cpp)
file(GLOB HEADER_FILES ${INCLUDE_DIR}/*.h)

add_executable(advent-of-code-2021 ${HEADER_FILES} ${SRC_FILES})

if (WIN32)
	set_property(TARGET advent-of-code-2021 PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/inputs/")
endif()

target_include_directories(advent-of-code-2021 PRIVATE ${INCLUDE_DIR})