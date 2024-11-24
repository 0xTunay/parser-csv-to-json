#include <memory>
#include <vector>
#include <json/json.h>

#include "../include/parceCSV.hpp"
#include "../rapidcsv/src/rapidcsv.h"
#include "../include/writeJSON.hpp"

/*
   all new class you can find in this https://github.com/d99kris/rapidcsv/tree/master/doc respository

 */


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


  for (size_t row = 0; row < doc->GetRowCount(); ++row){
    for (size_t col = 0; col < headers.size(); ++col)   {
      Json::Value json_row(Json::objectValue);

      json_row[headers[col]] = doc->GetCell<std::string>(col, row);

      json_data.append(json_row);
    }
  }
    writeJSON(jsonFile,json_data);
}
