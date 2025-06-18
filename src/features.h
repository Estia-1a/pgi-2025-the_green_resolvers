#ifndef FEATURES_H
#define FEATURES_H


void helloWorld();
void dimension(char *source_path);
void first_pixel(char *source_path);
void tenth_pixel(char *source_path);
void second_line(char *source_path);
void print_pixel(char *filename, int x, int y);
void max_pixel(char *source_path);
void min_pixel(char *filename);
void max_component(char *filename, char component);
void min_component(char *filename, char component);
void stat_report(char *filename);
void color_red(char *source_path);
void color_green(char *source_path);
void color_blue(char *source_path);
void color_gray(char *source_path);
void color_gray_luminance(char *filename);
#endif
