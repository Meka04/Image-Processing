//
// Created by dariu on 26/03/2024.
//
#include "Point.h"
#ifndef RECT_H
#define RECT_H



class Rectangle {
private:
    int x,y;
    int w,h;
public:
    Rectangle() = default;
    Rectangle(int x, int y, int w, int h);
    [[nodiscard]] int getX() const;
    [[nodiscard]] int getY() const;
    [[nodiscard]] int getHeight() const;
    [[nodiscard]] int getWidth() const;
    void setX(int x);
    void setY(int y);
    void setHeight(int h);
    void setWidth(int w);

    // Rectangle& operator+(const Point& other);
    // Rectangle& operator-(const Point& other);

    Rectangle& operator+(const Point& other);
    Rectangle& operator-(const Point& other);
    Rectangle& operator&(const Rectangle& other);
    Rectangle& operator|(const Rectangle& other);
};



#endif //RECT_H
