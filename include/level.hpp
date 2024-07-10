#pragma once
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include "point.hpp"

namespace abyss
{
    class level {
        private:
            std::vector<std::string> _map;
            std::string _name;
            Math::Point pos;
            std::map<char, std::string> _items;

        public:
            std::vector<std::string> &map();
            std::string name();
            std::map<char, std::string> items();
            level(std::string lvl_path);
            level() {};
            level &operator=(const level &lvl) {
                this->_items = lvl._items;
                this->_name = lvl._name;
                this->_map = lvl._map;
                return *this;
            }
            bool operator<(const level a) {
                return a._name < this->_name;
            }
            bool operator>(const level a) {
                return a._name > this->_name;
            }
            Math::Point player_pos();
            ~level() {};
    };
}