/*
** EPITECH PROJECT, 2024
** cpp project
** File description:
** MyTek 2 project
*/

#include <iostream>
#include <fstream>
#include "../include/player.hpp"

abyss::player::player(std::string name) : _name(name) {
    _direction.x = -1;
    _direction.y = 0;
}

int abyss::player::stock()
{
    return _gun_ball;
}

int abyss::player::life()
{
    return _life;
}

Math::Point& abyss::player::position()
{
    return _position;
}

Math::Vector& abyss::player::direction()
{
    return _direction;
}

void abyss::player::name(std::string name)
{
    _name = name;
}

void abyss::player::direction(Math::Vector direction)
{
    _direction = direction;
}

void abyss::player::position(Math::Point point)
{
    _position = point;
}

std::string abyss::player::name()
{
    return _name;
}
