#include <iostream>
#include <fstream>

#include "../include/writeJSON.hpp"


void writeJSON(const str &jsonFile,const Json::Value& json_data){
    std::ofstream file(jsonFile);
    if (!file.is_open()) {
        throw std::runtime_error("error. open open json file for writing: " + jsonFile);
    }

    file << json_data.toStyledString();

    file.close();

    std::cout << "file convent to json!" << jsonFile << std::endl;
    
}