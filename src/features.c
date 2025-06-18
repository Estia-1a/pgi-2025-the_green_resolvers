#include <estia-image.h>
#include <stdio.h>
#include <stdlib.h>

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


    

    
void max_pixel(char *source_path){
    unsigned char *data = NULL;
    int width, height, channels;

    if (read_image_data(source_path, &data, &width, &height, &channels) == 0){
        fprintf(stderr, "Erreur de lecture de l'image: %s\n", source_path );
        return;
    }

    int max_sum = -1;
    int max_x = 0, max_y= 0;
    unsigned char R=0, G=0, B=0;

    for (int y=0; y<height; y++){
        for(int x=0; x<width; x++){
            int pixel_index = (y*width+x)*channels;
            unsigned char r = data [pixel_index];
            unsigned char g = data [pixel_index + 1];
            unsigned char b = data [pixel_index + 2];

            int sum= r + g + b;

            if( sum > max_sum){
                max_sum = sum;
                max_x = x;
                max_y = y;
                R = r;
                G = g;
                B = b;


            }
        }
    }

    printf("max_pixel(%d, %d): %d, %d, %d\n", max_x, max_y, R, G, B);
}

void max_component(char *filename, char component){
    unsigned char *data;
    int width;
    int height;
    int channels;
    int max_value = -1;
    int max_x = 0, max_y = 0;

    if (read_image_data(filename, &data, &width, &height, &channels)==0){
        fprintf(stderr, "Erreur : impossible de lire l'image %s\n", filename);
        return; 
    }
    pixelRGB max_pixel = {0, 0, 0};
    for (int y=0 ; y <height ;  y++){
        for (int x=0 ;  x <width ; x++){
            pixelRGB pixel = get_pixel(data, width, height, x, y);
            int valeur = 0;
            if (component == 'R') {
                valeur = pixel.R;    
            }
            else if (component == 'G') {
                valeur = pixel.G;
            }
            else if (component == 'B') {
                valeur = pixel.B;
            }
            else {
                fprintf(stderr, "Erreur : composante invalide (R, G ou B attendu).\n");
                return;
            }
            if (valeur > max_value) {
                max_value = valeur;
                max_x = x;
                max_y = y;
                max_pixel = pixel;
            }
        }
    }
    if (component == 'R') {
    printf("max_component R (%d, %d): %d\n", max_x, max_y, max_pixel.R);
    } else if (component == 'G') {
    printf("max_component G (%d, %d): %d\n", max_x, max_y, max_pixel.G);
    } else if (component == 'B') {
    printf("max_component B (%d, %d): %d\n", max_x, max_y, max_pixel.B);
    }

}

void min_component(char *filename, char component){
    unsigned char *data;
    int width;
    int height;
    int channels;
    int min_value = 256;
    int min_x = 0, min_y = 0;

    if (read_image_data(filename, &data, &width, &height, &channels)==0){
        fprintf(stderr, "Erreur : impossible de lire l'image %s\n", filename);
        return; 
    }
    pixelRGB min_pixel = {255, 255, 255};
    for (int y=0 ; y <height ;  y++){
        for (int x=0 ;  x <width ; x++){
            pixelRGB pixel = get_pixel(data, width, height, x, y);
            int valeur = 0;
            if (component == 'R') {
                valeur = pixel.R;    
            }
            else if (component == 'G') {
                valeur = pixel.G;
            }
            else if (component == 'B') {
                valeur = pixel.B;
            }
            else {
                fprintf(stderr, "Erreur : composante invalide (R, G ou B attendu).\n");
                return;
            }
            if (valeur < min_value) {
                min_value = valeur;
                min_x = x;
                min_y = y;
                min_pixel = pixel;
            }
        }
    }
    if (component == 'R') {
    printf("min_component R (%d, %d): %d\n", min_x, min_y, min_pixel.R);
    } else if (component == 'G') {
    printf("min_component G (%d, %d): %d\n", min_x, min_y, min_pixel.G);
    } else if (component == 'B') {
    printf("min_component B (%d, %d): %d\n", min_x, min_y, min_pixel.B);
    }

}

void stat_report(char *filename) {
    if (freopen("stat_report.txt", "w", stdout) == NULL) {
        fprintf(stderr, "Erreur : impossible de rediriger stdout vers le fichier\n");
        return;
    }
    max_pixel(filename);
    printf("\n" );
 
    min_pixel(filename);
    printf("\n");
 
    max_component(filename, 'R' );
    printf("\n" );
 
    max_component(filename, 'G' );
    printf("\n" );
 
    max_component(filename, 'B');
    printf("\n");
 
    min_component(filename, 'R');
    printf("\n");
 
    min_component(filename, 'G' );
    printf("\n" );
 
    min_component(filename, 'B');
    printf("\n" );
 
     
    fflush(stdout);

    freopen("CON", "w", stdout);
}

void color_red(char *source_path) {
    int width, height, channels;
    unsigned char *data;

    if (read_image_data(source_path, &data, &width, &height, &channels) == 0) {
        fprintf(stderr, "Erreur : impossible de lire l'image %s\n", source_path);
        return;
    }
    for (int i = 0; i < width * height * channels; i += channels) {
        data[i + 1] = 0;
        data[i + 2] = 0; 
    }

    if (write_image_data("image_out.bmp", data, width, height) == 0) {
        fprintf(stderr, "Erreur : impossible d'écrire l'image image_out.bmp\n");
    }

    free(data);
}
void color_green(char *source_path) {
    int width, height, channels;
    unsigned char *data;
    if (read_image_data(source_path, &data, &width, &height, &channels) ==0){
        fprintf(stderr, "Erreur : impossible de lire l'image %s\n", source_path);
        return;
    }
    for (int i =0; i < width * height * channels; i += channels) {
        data[i] = 0;             
        if (channels >=3){
            data[i + 2]=0;     
        }
    }
    write_image_data("image_out.bmp", data, width, height);
    free(data);
    }

void color_blue(char *source_path) {
    int width, height, channels;
    unsigned char *data;
    if (read_image_data(source_path, &data, &width, &height, &channels) ==0){
        fprintf(stderr, "Erreur : impossible de lire l'image %s\n", source_path);
        return;
    }
    for (int i =0; i < width * height * channels; i += channels) {
        data[i] = 0;             
        data[i + 1]=0;     
        
    }
    write_image_data("image_out.bmp", data, width, height);
    free(data);
    }

void color_gray(char *source_path) {
    int width, height, channels;
    unsigned char *data;

    if (read_image_data(source_path, &data, &width, &height, &channels)==0) {
        fprintf(stderr, "Erreur : impossible de lire l'image %s\n", source_path);
        return;
    }
    for (int i = 0; i < width * height * channels; i +=channels) {
        unsigned char r=data[i];
        unsigned char g=data[i + 1];
        unsigned char b=data[i + 2];
        unsigned char gray = (r + g + b) / 3;
        data[i]=gray;
        data[i + 1]=gray;
        data[i + 2]=gray;
    }
    if (write_image_data("image_out.bmp", data, width, height)==0) {
        fprintf(stderr, "Erreur : impossible d'écrire l'image image_out.bmp\n");
    }
    free(data);
    }