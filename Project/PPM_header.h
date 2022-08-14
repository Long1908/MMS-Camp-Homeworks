#ifndef _HEADER_
#define _HEADER_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


typedef struct Pixel_Data{
    int Red_RGB_number;
    int Green_RGB_number;
    int Blue_RGB_number;
}Pixel;

typedef struct PPM_Image_Buffer {
    Pixel* data;
    int rown, coln;
}PPM;

int read_ppm_color_bitmap(char* filename, PPM* buf);
int write_ppm_color_bitmap(char *filename, PPM *buf);
void filter_color_component(PPM* buf, unsigned int rgb_mask);
void convert_to_grayscale(PPM* buf);
#endif