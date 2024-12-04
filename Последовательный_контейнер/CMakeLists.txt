cmake_minimum_required(VERSION 3.10)

# Название вашего проекта
project(SimpleVectorProject)

# Укажите стандарт C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Добавьте исполняемый файл и его исходный код
add_executable(SimpleVectorExecutable
    SimpleVector.cpp
    # Добавьте другие необходимые файлы, если есть
)

# Проверка компилятора и установка флагов
if (MSVC)
    target_compile_options(SimpleVectorExecutable PRIVATE /W4 /permissive-)
else ()
    target_compile_options(SimpleVectorExecutable PRIVATE -Wall -Wextra -Wpedantic)
endif()
