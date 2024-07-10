/*
** EPITECH PROJECT, 2024
** Paradigms Seminar
** File description:
** Day 11
*/
#include <stdlib.h>
#include <unistd.h>
#include "../include/point.hpp"

Math::Point::Point() {
    x = 0;
    y = 0;
}

Math::Point::Point(double _x, double _y) {
    x = _x;
    y = _y;
}

Math::Point::Point(const Math::Point& point) {
    this->x = point.x;
    this->y = point.y;
}

Math::Point::Point(const Math::Point&& point) {
    this->x = point.x;
    this->y = point.y;
}

Math::Point& Math::Point::operator=(const Math::Point& A) {
    this->x = A.x;
    this->y = A.y;
    return *this;
}

Math::Point& Math::Point::operator=(const Math::Point&& A) {
    this->x = A.x;
    this->y = A.y;
    return *this;
}

Math::Point Math::Point::operator+(const Vector& A) {
    Math::Point point;
    point.x = this->x + A.x;
    point.y = this->y + A.y;
    return point;
}

Math::Vector Math::Point::operator-(const Math::Point& A) {
    Vector res;
    res.x = this->x - A.x;
    res.y = this->y - A.y;
    return res;                
}