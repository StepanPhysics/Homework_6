
cmake_minimum_required(VERSION 3.8)

# Название вашего проекта
project(SimpleListProject)

# Укажите стандарт C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Добавьте исполняемый файл и его исходные файлы
add_executable(SimpleListExecutable
    Main_SimpleList.cpp
    SimpleList.h
 "Main_SimpleList.cpp")

# Добавьте нужные флаги компиляции, если необходимо
# target_compile_options(SimpleListExecutable PRIVATE -Wall -Wextra -Wpedantic)
