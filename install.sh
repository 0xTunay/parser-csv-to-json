#!/bin/zsh
cd build || mkdir -p build && cd build
cmake ..
make
./build/parser-csv-to-json
cd ..