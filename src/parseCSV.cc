#include <memory>
#include <vector>
#include <json/json.h>

#include "../include/parceCSV.hpp"
#include "../rapidcsv/src/rapidcsv.h"

void csv_parser(const str &csvFILE,const str &jsonFile){
    std::shared_ptr<rapidcsv::Document> doc = std::make_shared<rapidcsv::Document>(
    csvFILE, rapidcsv::LabelParams(0, 0));; 
    /*
    first str - headers, second points
    I using smart-pointer cuz idk size csv file
    */

   std::vector<str> headers = doc->GetColumnNames();

    /*json array*/
   Json::Value json_data(Json::arrayValue);
   
}
