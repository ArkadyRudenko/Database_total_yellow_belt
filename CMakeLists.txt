# mkdir build
# cd build
# cmake ..
# cmake --build .
# .\Debug\DataBase.exe

cmake_minimum_required(VERSION 3.18 FATAL_ERROR)

project(DataBase)

include_directories(include/database)
include_directories(include/parser)
include_directories(include/tests)


file(GLOB_RECURSE SOURCES "src/*.cpp")


add_executable(${PROJECT_NAME} ${SOURCES})


target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

set_target_properties(
		${PROJECT_NAME} PROPERTIES
		CXX_STANDART 17
		CXX_STANDART_REQUIRED ON
)
