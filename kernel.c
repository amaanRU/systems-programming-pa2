#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/*Notes:
-conversion formula: RGB -> YCbCr pixel using formula for ITU-R BT.601 conversion, needs round() 
-must have function w the following signature, void convert_to_YCrCb(unsigned char *rgb_pixels, unsigned char  *ycc_pixels, int width, int height)
-shouldnt crash if width or height is 0 but can return an array of 0's for ycc_pixels
-if any pixel differs by more than one value (e.g. abs( Python(YCbCr) - C_library(YCbCr)>1), u did sum wrong n will return error.

side notes:
-rgb values range from 0-255
- clamping: safe guard for image processing, makes sure its valid and doesnt fall outside the range of 8-bit image data (0-255)

*/

void convert_to_YCrCb(unsigned char *rgb_pixels, unsigned char *ycc_pixels, int width, int height){

    int tpixels = width * height;

    //if w or h = 0, fill ycc_pixels w array of zeros and return
    if(width <= 0 || height <= 0){
        int tbytes = width * height * 3; //3 bcuz each pixel require 3 bytes (r, g, b)
        for(int i = 0; i < tbytes; i++){
            ycc_pixels[i] = 0;
        }
        return;
    }

    for(int i  = 0; i < tpixels; i++){
        //rgb values
        int byte = i * 3; 
        unsigned int r = rgb_pixels[byte]; //color red of pixel
        unsigned int g = rgb_pixels[byte + 1]; //stores green after red 
        unsigned int b = rgb_pixels[byte + 2]; //stores blue after green
        
        //YCrCb values
        //GIVEN FORMULA - > DECLARE r g b 
        double y = round(0.299 * r + 0.587 * g + 0.114 * b);
        double cb = round(128 + (-0.168736 * r - 0.331264 * g + 0.5 * b));
        double cr = round(128 + (0.5 * r - 0.418688 * g - 0.081312 * b));

        //alternatively
        y = fmax(0, fmin(255,y));
        cb = fmax(0, fmin(255,cb));
        cr = fmax(0, fmin(255,cr));

        
        //converted values to the array 
        ycc_pixels[byte] = (unsigned char)y;
        ycc_pixels[byte + 1] = (unsigned char)cb;
        ycc_pixels[byte + 2] = (unsigned char)cr;
    }

}