#include <stdlib.h>
#include <stdio.h>
#include "bitmap.h"
#include "bitmodify.h" // Library to implement bitmap image modification for the assignment

#define XSIZE 2560 // Size of before image
#define YSIZE 2048

int main() {
	uchar *image = calloc(XSIZE * YSIZE * 3, 1); // Three uchars per pixel (RGB)
	readbmp("before.bmp", image);

	// Alter the image here
	char option;

    printf("Choose what to do with the image:\n");
    printf("a. Resize to 2x.\n");
    printf("b. Invert colors.\n");
    printf("Please enter an option from the main menu or any other key to exit: ");
    scanf("%c", &option);

    switch(option){
    case 'a':
        savebmp("after.bmp", resize(image, XSIZE, YSIZE), 2*XSIZE, 2*YSIZE);
        break;
    case 'b':
		invert_color(image, XSIZE, YSIZE);
		savebmp("after.bmp", image, XSIZE, YSIZE);
        break;
    default:
        break;
    }
    printf("Go and check your new image. Bye :)\n");

	free(image);
	return 0;
}
