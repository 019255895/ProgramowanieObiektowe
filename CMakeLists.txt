cmake_minimum_required(VERSION 3.17.2)
project (ProgramowanieObiektowe)

include_directories(include)
 
set(SOURCES src/mainapp.cpp, src/table.cpp)
 
file(GLOB SOURCES "src/*.cpp")
 
add_executable(main ${SOURCES})