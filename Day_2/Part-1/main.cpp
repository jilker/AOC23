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
    int output = 0;
    std::string line;
    while (getline(myfile, line)) {
        std::cout << line << std::endl;
        std::replace(line.begin(), line.end(), ':', ' ');
        std::replace(line.begin(), line.end(), ',', ' ');
        std::replace(line.begin(), line.end(), ';', ' ');
        std::stringstream ss(line);
        // GAME NUMBER
        std::string game;
        ss >> game >> game;
        std::cout << game << "\n";
        // SHOWS
        std::string color;
        int value;
        bool flg = true;
        while (ss >> value >> color) {
            std::cout << value << " " << color << "\n";
            //  12 red cubes, 13 green cubes, and 14 blue cubes
            if (value > 14) {
                flg = false;
                break;
            }
            if (color == "red" && value > 12) {
                flg = false;
                break;
            }
            if (color == "green" && value > 13) {
                flg = false;
                break;
            }
            if (color == "blue" && value > 14) {
                flg = false;
                break;
            }
        }
        if (flg)
            output += std::stoi(game);
    }
    std::cout << output << std::endl;
    return 0;
}