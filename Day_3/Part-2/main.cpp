#include <stdio.h>

#include <algorithm>
#include <array>
#include <fstream>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>

int main(int argc, char const *argv[]) {
    if (argc < 2) {
        std::cout << "Input not found" << std::endl;
        return 0;
    }
    std::ifstream myfile(argv[1]);
    if (!myfile) {
        std::cout << "Error loading path files" << std::endl;
        return 0;
    }
    // CODE
    std::vector<std::string> map;
    std::string line;
    while (getline(myfile, line)) {
        map.push_back('.' + line + '.');
    }
    std::string helper(map.at(0).size(), '.');
    map.insert(map.begin(), helper);
    map.push_back(helper);
    using Pos = std::pair<size_t, size_t>;
    using Gear = std::pair<int, Pos>;
    Pos pos{0, 0};
    std::vector<Gear> gears;
    std::string buffer;
    for (size_t i = 1; i < map.size() - 1; i++) {
        for (size_t j = 1; j < map.at(i).size() - 1; j++) {
            // if not number check to sum and clear
            if (!std::isdigit(map.at(i).at(j))) {
                if (pos.first != 0 && pos.second != 0) {
                    std::cout << buffer << std::endl;
                    gears.push_back(Gear(std::stoi(buffer), pos));
                }
                buffer.clear();
                pos.first = 0;
                pos.second = 0;
                continue;
            }
            buffer.push_back(map.at(i).at(j));
            if (pos.first != 0 && pos.second != 0)
                continue;
            // check to validate a number
            if (j > 0 && j < map.at(i).size() && i > 0 && i < map.size()) {
                for (size_t ii = i - 1; ii <= (i + 1) && !(pos.first != 0 && pos.second != 0); ii++) {
                    for (size_t jj = j - 1; jj <= (j + 1) && !(pos.first != 0 && pos.second != 0); jj++) {
                        if (map.at(ii).at(jj) == '*')
                            pos.first = ii;
                        pos.second = jj;
                    }
                }
            }
        }
    }
    std::cout << gears.size() << std::endl;
    int count;
    for (size_t i = 0; i < gears.size(); i++) {
        for (size_t j = i + 1; j < gears.size(); j++) {
            if (gears.at(i).second.first == gears.at(j).second.first && gears.at(i).second.second == gears.at(j).second.second) {
                std::cout << gears.at(i).first << "*" << gears.at(j).first << std::endl;
                count += gears.at(i).first * gears.at(j).first;
            }
        }
    }
    std::cout << count << std::endl;
    return 0;
}