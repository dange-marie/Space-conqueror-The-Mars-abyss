/*
** EPITECH PROJECT, 2024
** Paradigms Seminar
** File description:
** Day 11
*/
#include <stdlib.h>
#include <unistd.h>
#include "../include/vector.hpp"

Math::Vector::Vector(double _x, double _y) {
    x = _x;
    y = _y;
}

Math::Vector::Vector(const Vector& A) {
    this->x = A.x;
    this->y = A.y;
}

Math::Vector::Vector(const Vector&& A) {
    this->x = A.x;
    this->y = A.y;
}

Math::Vector& Math::Vector::operator=(const Vector& A) {
    this->x = A.x;
    this->y = A.y;
    return *this;
}

Math::Vector& Math::Vector::operator=(const Vector&& A) {
    this->x = A.x;
    this->y = A.y;
    return *this;
}

int Math::Vector::length() {
    double size = (x * x) + (y * y);
    return std::sqrt(size);
}

int Math::Vector::length_sqrt() {
    double size = (x * x) + (y * y);
    return size;
}

Math::Vector Math::Vector::operator+(const Vector& A) {
    Math::Vector res;
    res.x = this->x + A.x;
    res.y = this->y + A.y;
    return res;
}

Math::Vector Math::Vector::operator+=(const Vector& A) {
    this->x += A.x;
    this->y += A.y;
    return *this;
}

Math::Vector Math::Vector::operator-(const Vector& A) {
    Math::Vector res;
    res.x = this->x - A.x;
    res.y = this->y - A.y;
    return res;
}

Math::Vector Math::Vector::operator-=(const Vector& A) {
    this->x -= A.x;
    this->y -= A.y;
    return *this;
}

Math::Vector Math::Vector::operator*(const Vector& A) {
    Math::Vector res;
    res.x = this->x * A.x;
    res.y = this->y * A.y;
    return res;
}

Math::Vector Math::Vector::operator*(const double& A) {
    Math::Vector res;
    res.x = this->x * A;
    res.y = this->y * A;
    return res;
}

Math::Vector Math::Vector::operator*=(const Vector& A) {
    this->x *= A.x;
    this->y *= A.y;
    return *this;
}

Math::Vector Math::Vector::operator/(const Vector& A) {
    Math::Vector res;
    res.x = this->x / A.x;
    res.y = this->y / A.y;
    return res;
}

Math::Vector Math::Vector::operator/(const double& A) {
    Math::Vector res;
    res.x = this->x / A;
    res.y = this->y / A;
    return res;
}

Math::Vector Math::Vector::operator/=(const Vector& A) {
    this->x /= A.x;
    this->y /= A.y;
    return *this;
}

double Math::Vector::dot(Vector &B) {
    return ((x * B.x) + (y * B.y));
}

bool Math::Vector::near_zero() {
    double s = 1e-8;
    return (std::fabs(x) < s && std::fabs(y) < s);
}
