//
// Created by dariu on 26/03/2024.
//

#include "Rect.h"
#include <algorithm>
#include <iostream>

Rectangle::Rectangle(int x, int y, int w, int h) {
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
}

int Rectangle::getX() const {
    return this->x;
}
int Rectangle::getY() const {
    return this->y;
}
int Rectangle::getHeight() const {
    return this->h;
}
int Rectangle::getWidth() const {
    return this->w;
}

void Rectangle::setX(int x) {
    this->x = x;
}

void Rectangle::setY(int y) {
    this->y = y;
}

void Rectangle::setHeight(int h) {
    this->h = h;
}

void Rectangle::setWidth(int w) {
    this->w = w;
}

Rectangle& Rectangle::operator+(const Point& other) {
    this->x += other.getX();
    this->y += other.getY();
    return *this;
}

Rectangle& Rectangle::operator-(const Point& other) {
    this->x -= other.getX();
    this->y -= other.getY();
    return *this;
}

 Rectangle& Rectangle::operator&(const Rectangle&other) {

     if((other.x <= this->x + this->w && other.x >= this->x) && (other.y + other.h > this->y)) {
        unsigned int topRightX= std::min(this->x + this->w, other.x + other.w);
        unsigned int topRightY= std::min(this->y, other.y);
        unsigned int bottomLeftX = std::max(this->x, other.x);
        unsigned int bottomLeftY= std::max(this->y - this->h, other.y - other.h);
        unsigned int height = topRightY - bottomLeftY;
        unsigned int width = topRightX - bottomLeftX;
        Rectangle r(topRightX-width, bottomLeftY+height, width, height);
        return r;
     }
     else {
        std::cout<<"Nothing in common";
     }
 }

 Rectangle& Rectangle::operator|(const Rectangle&other) {
    if(other.h!=0 && other.w!=0){
    unsigned int _y = std::max(this->y, other.y);
    unsigned int _x = std::min(this->x, other.x);
    unsigned int bottomRightX = std::max(this->x + this->w, other.x + other.w);
    unsigned int bottomRightY = std::min(this->y - this->h, other.y - other.h);
    Rectangle r(_x, _y, bottomRightX - _x, _y - bottomRightY);
    return r;
    }
    else{
        std::cout<<"No second square";
    }
 }