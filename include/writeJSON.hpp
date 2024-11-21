#ifndef JSONWRITE_HPP
#define JSONWRITE_HPP

#include <json/json.h>
#include <string>

using str = std::string;

void writeJSON(const str &jsonFile,const Json::Value& json_data);

#endif //  WRITEJSON_HPP