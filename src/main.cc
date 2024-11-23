#include <iostream>
#include <string.h>

#include "../include/parceCSV.hpp"

int main(int argc,char *argv[]) {

  if(argc < 3 ){
    std::cerr << "using " << argv[0] << "input.csv --> output.json";
    return 1;
  }

  try {
        csv_parser(argv[1], argv[2]);
    } catch (const std::exception &ex) {
        std::cerr << "Ошибка: " << ex.what() << std::endl;
        return 1;
    }
  
  return 0;
  
}