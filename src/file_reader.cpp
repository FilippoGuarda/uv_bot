#include <iostream>
#include <fstream>
#include <string>
 
int main() {
  std::string filename = "test.txt";
  // open file for reading
  std::ifstream fin(filename);
  if (!fin.is_open()) {
    std::cout << "failed to open " << filename << '\n';
  } else {
    int pos1, pos2 = 0;
    fin.read(reinterpret_cast<char*>(&), sizeof d); // binary input
    int n;
    std::string s;
    if (fin >> n >> s)                               // text input
      std::cout << "read back from file: " << d << ' ' << n << ' ' << s << '\n';
  }
}