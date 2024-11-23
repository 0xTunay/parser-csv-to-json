cmake_minimum_required(VERSION 3.15)

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

find_package(PkgConfig REQUIRED)
pkg_check_modules(JSONCPP REQUIRED jsoncpp)

target_include_directories(core PUBLIC ${JSONCPP_INCLUDE_DIRS})
target_link_libraries(core PUBLIC ${JSONCPP_LIBRARIES})

add_executable(parser-csv-to-json src/main.cc)
target_link_libraries(parser-csv-to-json PRIVATE core)
