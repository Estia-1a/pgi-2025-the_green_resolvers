#include <estia-image.h>
#include <stdlib.h>

#include "utils.h"

/**
 * @brief Here, you have to define functions of the pixel struct : getPixel and setPixel.
 * 
 */

pixelRGB get_pixel(unsigned char*data, const unsigned int width, const unsigned int height, const unsigned int x, const unsigned int y){
    pixelRGB empty={0,0,0};
    if (data==NULL || x >= width || y >= height){
        return empty;
    }

    int index = (y * width + x)* 3;
    pixelRGB pixel= {data[index],data[index+1], data[index+2]};
    return pixel;

}