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

add_library(core STATIC ${SRC})

target_include_directories(core PUBLIC include)

add_library(rapidcsv INTERFACE)
target_include_directories(rapidcsv INTERFACE external/rapidcsv)

target_link_libraries(core PUBLIC rapidcsv)

add_executable(parser-csv-to-json src/main.cc)

target_link_libraries(parser-csv-to-json PRIVATE core)
