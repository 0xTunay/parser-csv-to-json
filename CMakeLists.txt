cmake_minimum_required(VERSION 3.15)

project(parser-csv-to-json)

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output)

add_subdirectory(OpenXLSX)

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

target_link_libraries(parser-csv-to-json OpenXLSX::OpenXLSX core)
