#include <algorithm>
#include <array>
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <vector>

std::string convert2dig(const std::string input) {
    std::cout << input << std::endl;
    std::string output;
    for (int i = 0; i < input.size(); i++) {
        std::string spelled;
        char c = input.at(i);
        if (isdigit(c)) {
            output += c;
        }
        for (int j = i; j < input.size(); j++) {
            char c = input.at(j);
            if (isdigit(c)) {
                break;
            }
            spelled += c;
            bool trg = false;
            switch (spelled.size()) {
                case 3:
                    if (spelled == "one") {
                        output += "1";
                        trg = true;
                    }
                    if (spelled == "two") {
                        output += "2";
                        trg = true;
                    }
                    if (spelled == "six") {
                        output += "6";
                        trg = true;
                    }
                    break;
                case 4:
                    if (spelled == "four") {
                        output += "4";
                        trg = true;
                    }
                    if (spelled == "five") {
                        output += "5";
                        trg = true;
                    }
                    if (spelled == "nine") {
                        output += "9";
                        trg = true;
                    }
                    break;
                case 5:
                    if (spelled == "three") {
                        output += "3";
                    }
                    if (spelled == "seven") {
                        output += "7";
                    }
                    if (spelled == "eight") {
                        output += "8";
                    }
                    break;
                default:
                    break;
            }
            std::cout << spelled << std::endl;
            if (trg) {
                break;
            }
            if (spelled.size() == 5)
                break;
        }
    }
    return output;
}
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
    int value = 0;
    while (getline(myfile, input)) {
        input = convert2dig(input);
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
        std::cout << pair[0] * 10 + pair[1] << std::endl;
        value += pair[0] * 10 + pair[1];
    }
    std::cout << value << std::endl;
    return 0;
}
