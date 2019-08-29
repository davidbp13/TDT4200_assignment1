#include <stdlib.h>
#include <stdio.h>
#include "bitmap.h"
#include "bitmodify.h" // Library in which the image modifications are implemented

#define XSIZE 2560 // Size of before image
#define YSIZE 2048

int main() {
	uchar *image = calloc(XSIZE * YSIZE * 3, 1); // Three uchars per pixel (RGB)
	readbmp("before.bmp", image);

	// Alter the image here
	// Simple menu which calls the diferent image modifications
	char option;

    printf("Choose what to do with the image:\n");
    printf("a. Resize to 2x.\n");
    printf("b. Invert colors.\n");
    printf("c. Flip upside down.\n");
    printf("Please enter an option from the main menu or enter any other key to exit: ");
    scanf("%c", &option);

    switch(option){
    case 'a': 
		resize(image, XSIZE, YSIZE);
        break;
    case 'b':
		invert_color(image, XSIZE, YSIZE);
        break;
    case 'c':
		upside_down(image, XSIZE, YSIZE);
        break;
    default:
		return 0;
    }
    
    printf("\nSUCCESS!!! Go and check your new image. Bye :)\n");

	free(image);
	return 0;
}
