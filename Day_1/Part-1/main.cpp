#include <algorithm>
#include <array>
#include <fstream>
#include <iostream>
#include <set>
#include <vector>
#include <string>
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
    std::string input;
    std::set<char> marker;
    int value = 0;
    while (getline(myfile, input)) {
        bool first = true;
        std::array<int, 2> pair;
        for (int i = 0; i < input.size(); i++) {
            const char p = input.at(i);
            if (isdigit(p))
                if (first) {
                    first = false;
                    pair[0] = p - '0';
                    pair[1] = p - '0';
                } else
                    pair[1] = p - '0';
        }
        std::cout << pair[0]*10 + pair[1] << std::endl;
        value += pair[0]*10  + pair[1];
    }
    std::cout << value << std::endl;
    return 0;
}
