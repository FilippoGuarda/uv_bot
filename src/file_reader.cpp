#include <iostream>
#include <fstream>
#include <string>
#include "file_reader_class.cpp"

using namespace std;

int main()
{
  GetRooms room;
  room.readFile("test.txt");
  vector<roomData> rooms = room.getRooms();
  for (int i = 0; i < rooms.size(); ++i)
  {
    std::cout << rooms[i].Name << " " << "\n"; 
    std::cout << rooms[i].x1 << " " << rooms[i].x2 << "\n";
  }
  return 0;
}
