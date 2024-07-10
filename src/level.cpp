/*
** EPITECH PROJECT, 2024
** cpp project
** File description:
** MyTek 2 project
*/

#include <iostream>
#include <fstream>
#include "../include/level.hpp"

abyss::level::level(std::string lvl_path)
{
    bool start = false;
    std::ifstream file(lvl_path);
    std::string line, player;
    int j = 0;

    if (!file.is_open()) {
        return;
    }
    std::getline(file, _name);
    std::getline(file, player);
    while (std::getline(file, line)) {
        if (line == "map") {
            start = true;
            continue;
        }
        if (!start) {
            _items.insert({line[0], line.substr(2)});
            std::cout << "Path " << line.substr(2) << std::endl;
        }
        else {
            int i = line.find("X");
            std::cout << line << std::endl;
            if (i != -1) {
                pos.x = i;
                pos.y = j;
            }
            _map.push_back(line);
            j += 1;
        }
    }
}

std::vector<std::string>& abyss::level::map()
{
    return _map;
}

std::string abyss::level::name()
{
    return _name;
}

std::map<char, std::string> abyss::level::items()
{
    return _items;
}

Math::Point abyss::level::player_pos()
{
    return pos;
}
