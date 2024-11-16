cmake_minimum_required(VERSION 3.10)


project(parser-csv-to-json)

set(CMAKE_CXX_STANDARD 23)

set(SRC
    src/parseCSV.cc
    src/writeJSON.cc
)

set(INCLUDE
    include/parceCSV.hpp
    include/writeJSON.hpp
)

add_library(core
    ${SRC}
    ${CORE_SRC}
)

add_executable(parser-csv-to-json
    src/main.cc
)