//
// Created by dariu on 28/03/2024.
//
#include "Size.h"
#include "Rect.h"
#include <string>
#include "Point.h"

#ifndef IMAGE_H
#define IMAGE_H



class Image
{
public:
    Image();
    Image(unsigned int w, unsigned int h);
    Image(const Image &other);
    Image& operator=(const Image &other);
    ~Image();
    bool load(std::string imagePath);
    [[nodiscard]] bool save(std::string imagePath) const;
    Image operator+(const Image &i);
    Image operator-(const Image &i);
    Image operator*(double s);
    bool getROI(Image &roiImg, Rectangle roiRect);
    bool getROI(Image &roiImg, unsigned int x, unsigned int y, unsigned int width, unsigned int height);
    [[nodiscard]] bool isEmpty() const;
    [[nodiscard]] Size size() const;
    [[nodiscard]] unsigned int width() const;
    [[nodiscard]] unsigned int height() const;
    unsigned char& at(unsigned int x, unsigned int y);
    unsigned char& at(Point pt);
    unsigned char* row(int y);
    void release();
    friend std::ostream& operator<<(std::ostream& os, const Image& dt);
    friend std::istream& operator>>(std::istream& is, Image& dt);
    static Image zeros(unsigned int width, unsigned int height);
    static Image ones(unsigned int width, unsigned int height);
private:
    unsigned char** m_data;
    unsigned int m_width;
    unsigned int m_height;
};

#endif //IMAGE_H
