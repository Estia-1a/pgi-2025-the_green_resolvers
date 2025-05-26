#include <estia-image.h>
#include <stdio.h>

#include "features.h"
#include "utils.h"

/**
 * @brief Here, you have to code features of the project.
 * Do not forget to commit regurlarly your changes.
 * Your commit messages must contain "#n" with: n = number of the corresponding feature issue.
 * When the feature is totally implemented, your commit message must contain "close #n".
 */

void helloWorld() {
    printf("Hello Dimitri !");
}

void dimension(char *source_path){
    int width, height, channel_count;
    unsigned char *data;
    if (read_image_data(source_path, &data, &width, &height, &channel_count)!=0){
        printf("dimension: %d, %d\n" , width, height);  
    }
}

void first_pixel(char *source_path){
    unsigned char R, B, G;
    int width, height, channel_count;
    unsigned char *data;
    if (read_image_data(source_path, &data, &width, &height, &channel_count)!=0){
        R = data[0];
        G = data[1];
        B = data[2];

        printf("first_pixel: %d, %d, %d \n", R, G, B);
    }
    else{
        fprintf(stderr,"Erreur : impossible de lire l'image %s \n",source_path);
    }

    
}
void tenth_pixel(char *source_path){
    unsigned char R, G, B;
    int width, height, channel_count;
    unsigned char *data;
    if (read_image_data(source_path, &data, &width, &height, &channel_count)!=0){
        if(width<10){
            printf("Erreur : l'image doit avoir au moins 10 pixels de large.\n");
            return;
        }
        int index = 9 *channel_count;
        R = data[index];
        G = data[index + 1];
        B = data[index + 2];
        printf("tenth_pixel: %d, %d, %d \n", R, G, B);

    }
    else{
        fprintf(stderr,"Erreur : impossible de lire l'image %s \n",source_path);
    }
    
}
void second_line(char *source_path){
    unsigned char R, G, B;
    int width, height, channel_count;
    unsigned char *data;
    if(read_image_data(source_path, &data, &width, &height, &channel_count) == 0){
        fprintf(stderr, "Erreur : impossible de lire l'image %s\n", source_path);
        return;
    }
    if(height<2){
        printf("Erreur : l'image doit avoir au 2 lignes de pixel.\n");
        return;
    }
        int index = width*channel_count;
        R = data[index];
        G = data[index + 1];
        B = data[index + 2];
        printf("second_line: %d, %d, %d \n", R, G, B);  
}

void print_pixel(char *filename, int x, int y){
    int n, width, height;
    unsigned char *data;
    if (read_image_data(filename, &data, &width, &height, &n)!=0){
        pixelRGB pixel = get_pixel(data,width,height,x,y);
        printf("print_pixel(%d, %d):%d,%d,%d\n", x, y, pixel.R, pixel.G, pixel.B);
    }
    else {
        fprintf(stderr,"Erreur : impossible de lire l'image %s \n",filename);
    }
}

void min_pixel(char *filename){
    int width, height, channel_count;
    unsigned char *data;
    if(read_image_data(filename, &data, &width, &height, &channel_count)==0){
        fprintf(stderr, "Erreur: impossible de lire l'image %s\n",filename);
        return;
    }
    int min_sum= 256*3+1;
    int min_x= 0, min_y= 0;
    pixelRGB min_pixel= {0,0,0};

    for(int y=0; y< height; y++){
        for(int x= 0; x<width; x++){
            pixelRGB pixel = get_pixel(data, width, height, x, y);
            int sum = pixel.R + pixel.G + pixel.B;

            if (sum<min_sum){
                min_sum = sum;
                min_x = x;
                min_y = y;
                min_pixel = pixel;
            } 
        }
    }
    printf("min_pixel (%d, %d): %d, %d, %d\n",min_x, min_y, min_pixel.R, min_pixel.G, min_pixel.B);
}


    

    

