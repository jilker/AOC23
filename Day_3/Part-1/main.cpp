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
    bool valid_number = false;
    int count = 0;
    std::string buffer;
    for (size_t i = 1; i < map.size() - 1; i++) {
        for (size_t j = 1; j < map.at(i).size() - 1; j++) {
            // if not number check to sum and clear
            if (!std::isdigit(map.at(i).at(j))) {
                if (valid_number) {
                    std::cout << buffer << std::endl;
                    count += std::stoi(buffer);
                }
                buffer.clear();
                valid_number = false;
                continue;
            }
            buffer.push_back(map.at(i).at(j));
            if (valid_number)
                continue;
            // check to validate a number
            if (j > 0 && j < map.at(i).size() && i > 0 && i < map.size()) {
                for (size_t ii = i - 1; ii <= (i + 1) && !valid_number; ii++) {
                    for (size_t jj = j - 1; jj <= (j + 1) && !valid_number; jj++) {
                        valid_number = (map.at(ii).at(jj) != '.' && !std::isdigit(map.at(ii).at(jj)));
                    }
                }
            }
        }
    }
    std::cout << count << std::endl;

    return 0;
}