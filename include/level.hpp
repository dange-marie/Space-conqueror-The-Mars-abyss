#include <iostream>
#include <vector>
#include <ostream>
#include <fstream>
#include <sstream>

class Level
{
    public:
        Level(std::string filepath) {
            bool onMap = false;
            std::ifstream file(filepath);
            if (file.is_open()) {
                std::string line;
                while (std::getline(file, line)) {
                    if (onMap) {
                        std::vector<char> row;
                        for (char c : line) {
                            row.push_back(c);
                        }
                        tiles.push_back(row);
                    } else {
                        if (line == "map") {
                            onMap = true;
                            continue;
                        }
                        std::stringstream ss(line);
                        std::string cmd, value;
                        ss >> cmd >> value;
                        if (cmd == "name") {
                            level_name = value;
                        }
                    }
                }
            } else {
                std::cout << "Failed to open file" << std::endl;
            }
        }

        void print() {
            for (std::vector<char> row : tiles) {
                for (char c : row) {
                    std::cout << c;
                }
                std::cout << std::endl;
            }
        }

        std::vector<std::vector<char>> getTiles() {
            return tiles;
        }

    private:
        std::vector<std::vector<char>> tiles;
        std::string level_name;
};