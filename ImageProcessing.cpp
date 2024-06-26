//
// Created by dariu on 05/04/2024.
//
#include <iostream>
#include "ImageProcessing.h"
#include "Image.h"
#include <cmath>

void BrightnessContrast::process(const Image &src, Image &dst) {
    dst = src;
    for (int i=0; i<src.width(); i++)
    {
        for (int j=0; j<src.height(); j++)
        {
            int p = a * int(dst.at(i, j)) + b;
            if (p>255) p=255;
            if (p<0) p=0;
            dst.at(i, j) = char(p);
        }
    }
}

void GammaCorrection::process(const Image &src, Image &dst) {
    dst = src;
    int p;
    for (int i=0; i<src.width(); i++)
    {
        for (int j=0; j<src.height(); j++)
        {
            p = dst.at(i,j);
            p = pow(p,y);
            if (p>255) p=255;
            if (p<0) p=0;
            dst.at(i,j) = p;
        }
    }
}
