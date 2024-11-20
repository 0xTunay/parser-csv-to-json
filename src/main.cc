
#include <iostream>

#include "../external/repidcsv/src/repidcsv.h"

int main(void) {

  rapidcsv::Document doc("../example.csv", rapidcsv::LabelParams(-1, -1));

  std::vector<float> close = doc.GetColumn<float>(5);
  std::cout << "Read " << close.size() << " values." << std::endl;

  long long volume = doc.GetCell<long long>(4, 2);
  std::cout << "Volume " << volume << " on 2017-02-22." << std::endl;
  
}