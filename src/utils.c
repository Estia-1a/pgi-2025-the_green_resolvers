#include <estia-image.h>

#include "utils.h"

/**
 * @brief Here, you have to define functions of the pixel struct : getPixel and setPixel.
 * 
 */

pixelRGB get_pixel(unsigned char*data, const unsigned int width, const unsigned int height, const unsigned int x, const unsigned int y){
  if (data==NULL || x >= width || y >= height); 
  return NULL;
  pixelRGB empty={0,0,0};
  return empty;  

  int index = (y * width + x)* n;
  pixelRGB p = {data[index], data[index+1], data[index+2]};
  return p;

}