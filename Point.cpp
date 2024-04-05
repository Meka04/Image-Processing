//
// Created by dariu on 26/03/2024.
//

#include "Point.h"

Point::Point() {
    this->x = 0;
    this->y = 0;
}

Point::Point(const int x, const int y) {
    this->x = x;
    this->y = y;
}

int Point::getX() const {
    return this->x;
}

int Point::getY() const {
    return this->y;
}

void Point::setX(int x) {
    this->x = x;
}

void Point::setY(int y) {
    this->y = y;
}



