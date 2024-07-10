#pragma once
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include "point.hpp"
#include "vector.hpp"

namespace abyss
{
    class player {
        protected:
            std::string _name;
            int _life;
            Math::Point _position;
            Math::Vector _direction;
            int _gun_ball;

        public:
            player(std::string name);
            player() {};
            int life();
            int stock();
            Math::Point& position();
            Math::Vector& direction();
            void name(std::string name);
            void position(Math::Point point);
            void direction(Math::Vector direction);
            std::string name();
            ~player() {};
    };
}