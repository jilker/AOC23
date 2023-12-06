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
        std::replace(line.begin(), line.end(), ':', ' ');
        std::replace(line.begin(), line.end(), ',', ' ');
        std::replace(line.begin(), line.end(), ';', ' ');
        std::stringstream ss(line);
        // GAME NUMBER
        std::string game;
        ss >> game >> game;
        // SHOWS
        std::string color;
        int value;
        // RGB
        std::array<int, 3> cubes = {0, 0, 0};
        while (ss >> value >> color) {
            if (color == "red") {
                if (cubes[0] < value)
                    cubes[0] = value;
            }
            if (color == "green") {
                if (cubes[1] < value)
                    cubes[1] = value;
            }
            if (color == "blue") {
                if (cubes[2] < value)
                    cubes[2] = value;
            }
        }
        output += cubes[0] * cubes[1] * cubes[2];
    }

    std::cout << output << std::endl;
    return 0;
}