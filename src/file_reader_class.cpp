#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>

using std::vector;
using std::string;


struct roomData
{
    string Name;
    int x1, x2, y1,y2;
};

class GetRooms
{

private:
    int i;
    int pos1, pos2;
    string _filepath = "";
    string areaName = {""};
    vector<roomData> _rooms;


public:
    void readFile(string filepath)
    {
        // open file for reading
        _filepath = filepath;
        std::ifstream fin(_filepath);
        i = 0;

        if (!fin.is_open())
        {
            std::cout << "failed to open " << _filepath << '\n';
        }
        else
        {
            while (fin >> areaName >> pos1 >> pos2)
            {
                std::cout << areaName << " " << pos1 << " " << pos2 << "\n";
                roomData newroom = {};
                newroom.Name = areaName;
                newroom.x1 = pos1;
                newroom.x2 = pos2;
                _rooms.push_back(newroom);
                i++;
            }
            std::cout << "made it trough"
                      << " \n";
        }
    }

    vector<roomData> getRooms()
    {
        return _rooms;
    }

};