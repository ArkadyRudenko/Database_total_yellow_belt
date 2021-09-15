# mkdir build
# cd build
# cmake..
# cmake --build .
# .\Debug\DataBase.exe

cmake_minimum_required(VERSION 3.20.5 FATAL_ERROR)

project(DataBase)

set(PROJECT_HEADERS_DIR ${PROJECT_SOURCE_DIR}/include)
set(PROJECT_SOURCES_DIR ${PROJECT_SOURCE_DIR}/src)

file(GLOB_RECURSE HEADERS ${PROJECT_HEADERS_DIR}/*.h)
file(GLOB_RECURSE SOURCES ${PROJECT_SOURCES_DIR}/*.cpp)

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})

include_directories(${PROJECT_HEADERS_DIR})

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

set_target_properties(
		${PROJECT_NAME} PROPERTIES
		CXX_STANDART 17
		CXX_STANDART_REQUIRED ON
)
