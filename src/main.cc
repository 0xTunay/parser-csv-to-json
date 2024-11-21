#include <iostream>
#include <string.h>

#include "../include/parceCSV.hpp"



int main(int argc,char *argv[]) {

  if(argc < 3 ){
    std::cerr << "using " << argv[0] << "input.csv --> output.json";
    return 1;
  }

  const str csvFile = argv[1];
  const str jsonFIle = argv[2];

  csv_parser(csvFile,jsonFIle);
  return 0;
  
}