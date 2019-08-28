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
    printf("Please enter an option from the main menu or enter any other key to exit: ");
    scanf("%c", &option);

    switch(option){
    case 'a': ;
		uchar *bigger_image = calloc(2 * XSIZE * 2 * YSIZE * 3, 1);
		resize(image, bigger_image, XSIZE, YSIZE);
        savebmp("after.bmp", bigger_image, 2*XSIZE, 2*YSIZE);
        free(bigger_image);
        break;
    case 'b':
		invert_color(image, XSIZE, YSIZE);
		savebmp("after.bmp", image, XSIZE, YSIZE);
        break;
    default:
		return 0;
    }
    printf("Go and check your new image. Bye :)\n");

	free(image);
	return 0;
}
