//
// Created by dariu on 28/03/2024.
//

#include <iostream>
#include "Image.h"
#include <string>
#include <fstream>
#include "Point.h"
#include "Rect.h"
#include <cstring>
#include <stdlib.h>

Image::Image() {
    this->m_data = nullptr;
    this->m_width = 0;
    this->m_height = 0;
}

Image::Image(unsigned int w, unsigned int h) {
    this->m_width = w;
    this->m_height = h;
    this->m_data = new unsigned char*[h];
    for(int i=0; i<this->m_height; i++)
    {
        this->m_data[i] = new unsigned char[w];
    }
    for(int a=0; a<this->m_height; a++)
    {
        for(int b=0; b<this->m_width; b++) {

            this->m_data[a][b] = 48;
        }
    }
}

Image::Image(const Image &other) {

    //release();
    this->m_height = other.m_height;
    this->m_width = other.m_width;
    this->m_data = new unsigned char*[other.m_height];
    for(int i=0; i<this->m_height; i++)
    {
        this->m_data[i] = new unsigned char[other.m_width];
    }
    for(int a=0; a<this->m_height; a++)
    {
        for(int b=0; b<this->m_width; b++) {

            this->m_data[a][b] = other.m_data[a][b];
        }
    }
}

Image::~Image(){
    for(int i=0; i<this->m_height; i++)
    {
        delete[] m_data[i];
    }
    delete[] m_data;
}

void Image::release() {
    for(int i=0; i<this->m_width; i++)
    {
        delete[] m_data[i];
    }
    delete[] m_data;
}

Image& Image::operator=(const Image &other) {
    if (this != &other) {
        for (int i = 0; i < this->m_height; i++) {
            delete[] m_data[i];
        }
        delete[] m_data;
        this->m_height = other.m_height;
        this->m_width = other.m_width;
        this->m_data = new unsigned char *[other.m_height];
        for (int i = 0; i < other.m_height; i++) {
            m_data[i] = new unsigned char[m_width];
        }
        for (int i = 0; i < other.m_height; i++) {
            for (int j = 0; j < other.m_width; j++) {
                this->m_data[i][j] = other.m_data[i][j];
            }
        }
        return *this;
    }
}

unsigned int Image::height() const {
    return this->m_height;
}
unsigned int Image::width() const {
    return this->m_width;
}

Size Image::size() const {
    Size s(this->m_width, this->m_height);
    return s;
}

bool Image::isEmpty() const {
    if(this->m_data == nullptr && this->m_width == 0 && this->m_height == 0)
        return true;
    return false;
}

unsigned char* Image::row(int y) {
    return this->m_data[y];
}

std::ostream &operator<<(std::ostream &os, const Image &dt) {
    os<<"P2\n";
    os<<dt.m_width<<" "<<dt.m_height<<"\n";
    os<<"255\n";
    for(int i=0; i<dt.m_height; i++)
    {
        for(int j=0; j<dt.m_width; j++)
        {
            os<<int(dt.m_data[i][j])<<" ";
        }
        os<<std::endl;
    }
    return os;
}

std::istream &operator>>(std::istream &is, Image &dt){
    std::string format;
    is>>format;
    if(format!="P2")
    {
        std::cerr<<"Invalid format\n";
        return is;
    }
    dt.release();
    is>>dt.m_width>>dt.m_height;
    dt.m_data = new unsigned char*[dt.m_height];
    for(int i=0; i<dt.m_height; i++)
    {
        dt.m_data[i] = new unsigned char[dt.m_width];
    }

    unsigned int maxVal;
    is>>maxVal;
    if(maxVal > 255)
    {
        std::cerr<<"Invalid pixel value";
        return is;
    }

    for(int i=0; i<dt.m_height; i++)
    {
        for(int j=0; j<dt.m_width; j++)
        {
            is>>dt.m_data[i][j];
        }
    }
    return is;
}

bool Image::save(std::string imagePath) const {
    std::ofstream file(imagePath);
    if(!file.is_open()) return false;
    file<<*this;
    file.close();
    return true;
}

bool Image::load(std::string imagePath) {
    std::ifstream file(imagePath);

    if(!file.is_open())
    {
        std::cerr << "Failed to open the file\n";
        return false;
    }

    std::string format;
    file>>format;
    if(format!="P2")
    {
        std::cerr<<"Invalid format\n";
        return false;
    }

    release();
    int w,h;
    file>>w>>h;
    this->m_width = w;
    this->m_height = h;
    this->m_data = new unsigned char*[this->m_height];
    for(int i=0; i<this->m_height; i++)
    {
        this->m_data[i] = new unsigned char[this->m_width];
    }

    unsigned int maxVal;
    file>>maxVal;
    if(maxVal > 255)
    {
        std::cerr<<"Invalid pixel value";
        return false;
    }

    for(int i=0; i<this->m_height; i++)
    {
        for(int j=0; j<this->m_width; j++)
        {
            int pixel;
            file>>pixel;
            //itoa(pixel,this->m_data[i][j],10);
            this->m_data[i][j] = pixel;
        }
    }
    file.close();
    return true;
}

Image Image::operator+(const Image &i) {
    if(this->m_width!=i.m_width || this->m_height!=i.m_height)
    {
        std::cout<<"Images have different sizes";
        return *this;
    }
    else{
        for(int a=0; a<this->m_height; a++)
        {
            for(int b=0; b<this->m_width; b++)
            {
                this->m_data[a][b] = this->m_data[a][b] + i.m_data[a][b];;
            }
        }
    }
    return *this;
}

Image Image::operator-(const Image &i) {
    if(this->m_width!=i.m_width || this->m_height!=i.m_height)
    {
        std::cout<<"Images have different sizes";
        return *this;
    }
    else{
        for(int a=0; a<this->m_height; a++)
        {
            for(int b=0; b<this->m_width; b++)
            {
                this->m_data[a][b] = this->m_data[a][b] - i.m_data[a][b];;
            }
        }
    }
    return *this;
}

Image Image::operator*(double s) {
        for(int a=0; a<this->m_height; a++)
        {
            for(int b=0; b<this->m_width; b++)
            {
                this->m_data[a][b] *= s;
            }
        }
    return *this;
}

unsigned char& Image::at(Point pt) {
    if(pt.getX()<this->m_width && pt.getY()<this->m_height) return this->m_data[pt.getY()][pt.getX()];
}
unsigned char& Image::at(unsigned int x, unsigned int y) {
    if(x<this->m_width && y<this->m_height) return this->m_data[y][x];
}

Image Image::zeros(unsigned int width, unsigned int height) {
    Image img(width, height);
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<=width; j++)
        {
            img.at(i,j) = 0;
        }
    }
    return img;
}

Image Image::ones(unsigned int width, unsigned int height) {
    Image img(width, height);
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<=width; j++)
        {
            img.at(i,j) = 1;
        }
    }
    return img;
}

bool Image::getROI(Image &roiImg, Rectangle roiRect) {
    if(roiRect.getX()>=0 && roiRect.getY()>=0 && roiRect.getY()+roiRect.getHeight()<=roiImg.m_height && roiRect.getX()+roiRect.getWidth()<=roiImg.m_width)
    {
        this->m_height = roiRect.getHeight();
        this->m_width = roiRect.getWidth();
        this->m_data = new unsigned char *[roiRect.getHeight()];
        for(int i=roiRect.getY(); i<roiRect.getHeight(); i++)
        {
            for(int j=roiRect.getX(); j<=roiRect.getWidth(); j++)
            {
                roiImg.m_data[i][j] = this->m_data[i][j];
            }
        }
        return true;
    }
    return false;
}

bool Image::getROI(Image &roiImg, unsigned int x, unsigned int y, unsigned int width, unsigned int height) {
    if(y+height<=roiImg.m_height && x+width<=roiImg.m_width)
    {
        this->m_height = height;
        this->m_width = width;
        this->m_data = new unsigned char *[height];
        for(unsigned int i=y; i<height; i++)
        {
            for(unsigned int j=x; j<=width; j++)
            {
                roiImg.m_data[i][j] = this->m_data[i][j];
            }
        }
        return true;
    }
    return false;
}