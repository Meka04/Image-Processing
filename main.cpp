#include <iostream>
#include "Image.h"
#include "Size.h"
#include "Rect.h"
#include "Point.h"
#include "ImageProcessing.h"

int main() {
    Image img;
    Image result;
    BrightnessContrast br{1,0};
    //img.load("../apollonian_gasket.ascii.pgm");
    img.load("../casablanca.ascii.pgm");
    //img.load("../barbara.ascii.pgm");
    br.process(img,result);
    GammaCorrection g{1.3};
    g.process(img, result);
    result.save("../image3.txt");
    std::cout<<"Gud";

    return 0;
}
