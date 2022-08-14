#include "PPM_header.h"

//This is main.c
int main(int argc, char *argv[])
{
    PPM* img1 = malloc(sizeof(PPM));
    read_ppm_color_bitmap(argv[1], img1);
    int opt, g;
    for(int i = 0; i < argc; i++)
    {

        if((strcmp(argv[i], "-g")) == 0) {
            convert_to_grayscale(img1);
        }
        if (((strcmp(argv[i], "-f")) == 0) && (i + 1) < argc) {
            if((strcmp(argv[i + 1], "r")) == 0) {
                filter_color_component(img1, 1);
            }
            else if((strcmp(argv[i + 1], "g")) == 0) {
                filter_color_component(img1, 2);
            }
            else if(((strcmp(argv[i + 1], "rg")) == 0) || ((strcmp(argv[i + 1], "gr")) == 0)) {
                filter_color_component(img1, 3);
            }
            else if((strcmp(argv[i + 1], "b")) == 0) {
                filter_color_component(img1, 4);
            }
            else if(((strcmp(argv[i + 1], "rb")) == 0) || ((strcmp(argv[i + 1], "br")) == 0)) {
                filter_color_component(img1, 5);
            }
            else if(((strcmp(argv[i + 1], "bg")) == 0) || ((strcmp(argv[i + 1], "gb")) == 0)) {
                filter_color_component(img1, 6);
            }
            else if(((strcmp(argv[i + 1], "rgb")) == 0) || (((strcmp(argv[i + 1], "rbg")) == 0) || ((strcmp(argv[i + 1], "gbr")) == 0)) || ((strcmp(argv[i + 1], "grb")) == 0) || ((strcmp(argv[i + 1], "brg")) == 0) || ((strcmp(argv[i + 1], "bgr")) == 0)) {
                filter_color_component(img1, 7);
            }
            else {
                perror("Invalid colours to filter! \n");
            }
        }
        if ((strcmp(argv[i], "-b")) == 0) {
            FILE* fb = fopen(argv[3], "wb");
            fwrite(img1, sizeof(PPM), sizeof(img1->coln * img1->rown), fb);
            fclose(fb);
        }
        if ((strcmp(argv[i], "-t")) == 0) { 
            write_ppm_color_bitmap(argv[3], img1);
        }
    }
    write_ppm_color_bitmap(argv[2], img1);
    return 0;
}