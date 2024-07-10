/*
** EPITECH PROJECT, 2024
** Paradigms Seminar
** File description:
** Day 11
*/
#pragma once
#include <iostream>
#include <cmath>

namespace Math {
    class Vector {
        public:
            double x;
            double y;

            Vector(double _x = 0, double _y = 0);
            Vector(const Vector& A);
            Vector(const Vector&& A);
            Vector& operator=(const Vector& A);
            Vector& operator=(const Vector&& A);
            int length();
            int length_sqrt();
            Vector operator+(const Vector& A);
            Vector operator+=(const Vector& A);
            Vector operator-(const Vector& A);
            Vector operator-=(const Vector& A);
            Vector operator*(const Vector& A);
            Vector operator*(const double& A);
            Vector operator*=(const Vector& A);
            Vector operator/(const Vector& A);
            Vector operator/(const double& A);
            Vector operator/=(const Vector& A);
            bool near_zero();
            double dot(Vector &B);
            Vector cross_product(Vector &B);
            ~Vector() {}
    };
}

inline Math::Vector operator*(const double& A, const Math::Vector& V) {
    Math::Vector res;
    res.x = V.x * A;
    res.y = V.y * A;
    return res;
}

inline Math::Vector operator/(const double& A, const Math::Vector& V) {
    return (1 / A) * V;
}
