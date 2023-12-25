#include <stdio.h>

#include <algorithm>
#include <array>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
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

    // std::ifstream myfile("/home/vicquecon/AOC23/Day_4/Part-1/example.txt");
    // if (!myfile) {
    //     std::cout << "Error loading path files" << std::endl;
    //     return 0;
    // }

    // CODE
    std::string line;
    std::array<int, 400> scratchcards = {0};
    int count = 0;
    while (getline(myfile, line)) {
        bool jump = false;
        std::vector<int> own;
        std::vector<int> winners;
        std::replace(line.begin(), line.end(), ':', ' ');
        std::stringstream ss(line);
        // GAME NUMBER
        std::string game;
        ss >> game >> game;
        std::cout << "Game -> " << game << std::endl;
        int last_game = std::stoi(game);
        scratchcards.at(last_game) += 1;
        while (getline(ss, game, ' ')) {
            if (game.empty())
                continue;
            if (game.find('|') != std::string::npos) {
                jump = !jump;
                continue;
            }

            if (!isdigit(game.at(0))) {
                continue;
            }
            (jump) ? own.push_back(std::stoi(game)) : winners.push_back(std::stoi(game));
        }
        std::cout << std::endl;

        std::cout << "Own"
                  << "\n";
        for (size_t i = 0; i < own.size(); i++) {
            std::cout << own.at(i) << "  ";
        }
        std::cout << std::endl;
        std::cout << "Winners"
                  << "\n";
        for (size_t i = 0; i < winners.size(); i++) {
            std::cout << winners.at(i) << "  ";
        }
        std::cout << std::endl;

        std::sort(own.begin(), own.end());
        std::sort(winners.begin(), winners.end());
        int rep = 0;
        auto it_own = own.begin();
        auto it_winners = winners.begin();
        while (it_own != own.end() && it_winners != winners.end()) {
            if (*it_own < *it_winners)
                ++it_own;
            else {
                if (!(*it_winners < *it_own)) {
                    *it_own++;  // *first1 and *it_winners are equivalent.
                    rep++;
                }
                ++it_winners;
            }
        }
        std::cout << "Num of rep -> " << rep << std::endl;
        for (size_t i = last_game + 1; i < last_game + rep + 1; i++) {
            std::cout <<  "Add cards " <<  i  << std::endl;
            scratchcards.at(i) += 1 *scratchcards.at(last_game);
        }
    }

    for (size_t i = 0; i < scratchcards.size(); i++) {
        count += scratchcards.at(i);
    }

    std::cout << count << "\n";
    return 0;
}