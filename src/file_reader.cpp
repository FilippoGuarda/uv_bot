#include <iostream>
#include <fstream>
#include <string>
 
int main() {
  std::string filename = "test.txt";
  // open file for reading
  std::ifstream fin(filename);
  std::string areaName {};
  int pos1, pos2;
  if (!fin.is_open()) {
    std::cout << "failed to open " << filename << '\n';
  } else {
    while(fin >> areaName >> pos1 >> pos2){
      std::cout << areaName << " " << pos1 << " " << pos2 << "\n";
    }
    std::cout << "made it trough" << " \n";
    return 0;
  }
}