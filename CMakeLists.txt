cmake_minimum_required(VERSION 3.15)

# Проект
project(parser-csv-to-json)

# Установка стандарта C++
set(CMAKE_CXX_STANDARD 23)

# Указание директорий для сборки
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output)

# Подключение подкаталога OpenXLSX
add_subdirectory(OpenXLSX)

# Исходные файлы
set(SRC
    src/parseCSV.cc
    src/writeJSON.cc
)

set(INCLUDE
    include/parceCSV.hpp
    include/writeJSON.hpp
)

# Создание библиотеки core
add_library(core
    ${SRC}
    ${CORE_SRC}
)

# Создание исполнимого файла для проекта
add_executable(parser-csv-to-json
    src/main.cc
)

# Линковка с библиотекой OpenXLSX
target_link_libraries(parser-csv-to-json OpenXLSX::OpenXLSX core)
