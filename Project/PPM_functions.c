#include "PPM_header.h"

int read_ppm_color_bitmap(char* filename, PPM* buf){
    FILE* f = fopen(filename, "r");
    if(f == NULL)
    {
        printf("1 Couldn't open file. Exit function.\n");
        return -1;
    }
    //fseek(f, 0, SEEK_SET);
    fseek(f, 3, SEEK_SET);
    fscanf(f, "%d", &buf->coln);
    fscanf(f, "%d", &buf->rown);
    int picture_size =  buf->coln * buf->rown;
    printf("%d %d %d\n", buf->coln, buf->rown, picture_size); //This was just a test of everythig was alright, but now the code does not work without this line. It says corrupted size.
    buf->data = malloc(sizeof(int) * picture_size * 3);
    if(!buf->data)
    {
        printf("Not allocated memory!");
        exit(-1);
    }
    int row = buf->rown, col = buf->coln, seek_position = 0;
    while(row != 0)
    {
        ++seek_position;
        row /= 10;
    }
    while(col != 0)
    {
        ++seek_position;
        col /= 10;
    }
    fseek(f, 8 + seek_position, SEEK_SET);
    for(long int i = 0; i < picture_size; i++)
    {
        fscanf(f, "%d", &(((buf->data) + i)->Red_RGB_number));
        fscanf(f, "%d", &(((buf->data) + i)->Green_RGB_number));
        fscanf(f, "%d", &(((buf->data) + i)->Blue_RGB_number));
    }
    fclose(f);
    return 0;
}

int write_ppm_color_bitmap(char *filename, PPM *buf){
    FILE* f = fopen(filename, "w+");
    if(f == NULL)
    {
        printf("2 Couldn't open file. Exit function.\n");
        return -1;
    }
    int picture_size = buf->coln * buf->rown;
    fputs("P3\n", f);
    fprintf(f, "%d %d\n", buf->coln, buf->rown);
    fputs("255\n", f);
    for(int i = 0; i < picture_size; i++)
    {
        fprintf(f, "%d ", ((buf->data) + i)->Red_RGB_number);
        fprintf(f, "%d ", ((buf->data) + i)->Green_RGB_number);
        fprintf(f, "%d ", ((buf->data) + i)->Blue_RGB_number);
    }   
    fclose(f);
    return 0;
}

void filter_color_component(PPM* buf, unsigned int rgb_mask){
    int picture_size =  buf->coln * buf->rown;
    if((rgb_mask & (1 << 0)) == 0)
    {
        for(int i = 0; i < picture_size; i++)
        {
            ((buf->data) + i)->Red_RGB_number = 0;
        }
    }
    if((rgb_mask & (1 << 1)) == 0)
    {        for(int i = 0; i < picture_size; i++)
        {
            ((buf->data) + i)->Green_RGB_number = 0;
        }
    }
    if((rgb_mask & (1 << 2)) == 0)
    {
        for(int i = 0; i < picture_size; i++)
        {
            ((buf->data) + i)->Blue_RGB_number = 0;
        }
    }
}

void convert_to_grayscale(PPM* buf){
    int picture_size = buf->coln * buf->rown;
    for(int i = 0; i < picture_size; i++)
    {
        (buf->data + i)->Red_RGB_number = (buf->data + i)->Red_RGB_number * 0.3 + (buf->data + i)->Green_RGB_number * 0.59 + (buf->data + i)->Blue_RGB_number * 0.11;
        (buf->data + i)->Green_RGB_number = (buf->data + i)->Red_RGB_number * 0.3 + (buf->data + i)->Green_RGB_number * 0.59 + (buf->data + i)->Blue_RGB_number * 0.11;
        (buf->data + i)->Blue_RGB_number = (buf->data + i)->Red_RGB_number * 0.3 + (buf->data + i)->Green_RGB_number * 0.59 + (buf->data + i)->Blue_RGB_number * 0.11;
        if(((buf->data + i)->Red_RGB_number != (buf->data + i)->Green_RGB_number) || 
           ((buf->data + i)->Red_RGB_number != (buf->data + i)->Blue_RGB_number) ||
           ((buf->data + i)->Blue_RGB_number != (buf->data + i)->Green_RGB_number))
            --i;
    }
}