//
// Created by dariu on 26/03/2024.
//

#ifndef POINT_H
#define POINT_H


class Point {

private:
    int x, y;
public:
    Point();
    Point(int x, int y);
    [[nodiscard]] int getX() const;
    [[nodiscard]] int getY() const;
    void setX(int x);
    void setY(int y);
};


#endif //POINT_H
