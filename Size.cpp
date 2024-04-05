//
// Created by dariu on 26/03/2024.
//

#include "Size.h"

Size::Size(const unsigned int w, const unsigned int h) {
    this->w = w;
    this->h = h;
}

unsigned int Size::getHeight() const {
    return this->h;
}

unsigned int Size::getWidth() const {
    return this->w;
}

void Size::setHeight(const unsigned int h) {
    this->h = h;
}

void Size::setWidth(const unsigned int w) {
    this->w = w;
}

bool Size::operator==(const Size& other) const {
    if (this->w * this->h == other.w * other.h)
        return true;
    return false;
}

bool Size::operator<=(const Size& other) const{
    if (this->w * this->h <= other.w * other.h)
        return true;
    return false;
}

bool Size::operator>=(const Size& other) const {
    if(this->w * this->h >= other.w * other.h)
        return true;
    return false;
}

bool Size::operator<(const Size& other) const {
    if (this->w * this->h < other.w * other.h)
        return true;
    return false;
}

bool Size::operator>(const Size& other) const {
    if (this->w * this->h > other.w * other.h)
        return true;
    return false;
}
