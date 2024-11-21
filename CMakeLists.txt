cmake_minimum_required(VERSION 3.15)

# Название проекта
project(parser-csv-to-json)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SRC
    src/parseCSV.cc
    src/writeJSON.cc
)

set(INCLUDE
    include/parseCSV.hpp
    include/writeJSON.hpp
)

# Добавляем библиотеку core
add_library(core STATIC ${SRC})

# Указываем директорию для заголовочных файлов
target_include_directories(core PUBLIC include)

# Добавляем INTERFACE библиотеку для rapidcsv
add_library(rapidcsv INTERFACE)
target_include_directories(rapidcsv INTERFACE external/rapidcsv)

# Линкуем core с rapidcsv
target_link_libraries(core PUBLIC rapidcsv)

# Добавляем пути для заголовочных файлов и библиотеки JsonCpp
include_directories("/usr/include/jsoncpp")
link_directories("/usr/lib")

# Линкуем JsonCpp
target_link_libraries(core PUBLIC jsoncpp)

# Создаём исполнимый файл
add_executable(parser-csv-to-json src/main.cc)

# Линкуем исполнимый файл с библиотекой core и JsonCpp
target_link_libraries(parser-csv-to-json PRIVATE core jsoncpp)
