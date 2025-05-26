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
        printf("Dimensions : %d, %d\n" , width, height);  
    }
}

void couleur_premier_pixel(char *source_path){
    unsigned char R, B, G;
    int width, height, channel_count;
    unsigned char *data;
    if (read_image_data(source_path, &data, &width, &height, &channel_count)!=0){
        R = data[0];
        G = data[1];
        B = data[2];

        printf("la couleur du premier pixel est : %d, %d, %d \n", R, G, B);
    }
    else{
        fprintf(stderr,"Erreur : impossible de lire l'image %s \n",source_path);
    }

    
}
void couleur_10eme_pixel(char *source_path){
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
        printf("la couleur du dixieme pixel est : %d, %d, %d \n", R, G, B);

    }
    else{
        fprintf(stderr,"Erreur : impossible de lire l'image %s \n",source_path);
    }
    
}
void couleur_premier_pixel_L2(){
    unsigned char R, G, B;
    int width, height, channel_count;
    unsigned char *data;
    if (read_image_data(source_path, &data, &width, &height, &channel_count)!=0){
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
    else{
        fprintf(stderr,"Erreur : impossible de lire l'image %s \n",source_path);
    }
}
void pixellisation_RVB(){
    
}