/*
** EPITECH PROJECT, 2024
** Paradigms Seminar
** File description:
** Day 11
*/
#pragma once
#include "vector.hpp"

namespace Math {
    class Point {
        public:
            double x;
            double y;
            Point();
            Point(double _x, double _y);
            Point(const Point& point);
            Point(const Point&& point);
            Point& operator=(const Point& A);
            Point& operator=(const Point&& A);
            Point operator+(const Vector& A);
            Vector operator-(const Point& A);
            ~Point() {}
    };
}
