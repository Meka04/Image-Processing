//
// Created by dariu on 05/04/2024.
//

#include "Image.h"
#ifndef IMAGEPROCESSV2_IMAGEPROCESSING_H
#define IMAGEPROCESSV2_IMAGEPROCESSING_H


class ImageProcessing {
public:
    virtual void process(const Image& src, Image& dst) = 0;
};

class BrightnessContrast : public ImageProcessing{
private:
    double a,b;
public:
    BrightnessContrast(): a{1}, b{0}{};
    BrightnessContrast(double _a, double _b): a{_a}, b{_b}{};
    void process(const Image& src, Image& dst) override;
};

class GammaCorrection: public ImageProcessing{
private:
    double y;
public:
    GammaCorrection(): y{1}{};
    GammaCorrection(double _y): y{_y}{};
    void process(const Image& src, Image& dst) override;
};

class Convulsion: public ImageProcessing{
private:

};

#endif //IMAGEPROCESSV2_IMAGEPROCESSING_H
