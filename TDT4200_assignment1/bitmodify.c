#include <stdlib.h>
#include "bitmap.h"	
#include "bitmodify.h"

void resize(uchar* array, int x, int y){
	uchar *bigger_array = calloc(2 * x * 2 * y * 3, 1); // Allocate space for empty image with twice widht and twice the heigth
	// This loops will fill the new image with duplicate pixels of the original
	for (int i=0; i<y; i++ ) { // To iterate through rows
		for (int j=0; j<x*3; j+=3) { // To iterate through columns (and each pixel component)
			// Duplicates corresponding pixel in new image
			bigger_array[(3 * i * 2*x + j)*2 + 0] = array[3 * i * x + j + 0]; // 3 * i * 2*x since the image is now twice the width and (...)*2 because is twice the height
			bigger_array[(3 * i * 2*x + j)*2 + 1] = array[3 * i * x + j + 1];
			bigger_array[(3 * i * 2*x + j)*2 + 2] = array[3 * i * x + j + 2];
			
			// Duplicates right pixel neighbor in new image
			bigger_array[(3 * i * 2*x + j)*2 + 0 + 3] = array[3 * i * x + j + 0];
			bigger_array[(3 * i * 2*x + j)*2 + 1 + 3] = array[3 * i * x + j + 1];
			bigger_array[(3 * i * 2*x + j)*2 + 2 + 3] = array[3 * i * x + j + 2];
			
			// Duplicates upper pixel neighbor in new image
			bigger_array[(3 * i * 2*x + j)*2 + 2*3*x + 0] = array[3 * i * x + j + 0]; // 2*3*x to jump to upper row
			bigger_array[(3 * i * 2*x + j)*2 + 2*3*x + 1] = array[3 * i * x + j + 1];
			bigger_array[(3 * i * 2*x + j)*2 + 2*3*x + 2] = array[3 * i * x + j + 2];
			
		    // Duplicates right upper pixel neighbor in new image
			bigger_array[(3 * i * 2*x + j)*2 + 2*3*x + 0 + 3] = array[3 * i * x + j + 0];
			bigger_array[(3 * i * 2*x + j)*2 + 2*3*x + 1 + 3] = array[3 * i * x + j + 1];
			bigger_array[(3 * i * 2*x + j)*2 + 2*3*x + 2 + 3] = array[3 * i * x + j + 2];
		}
	}
	savebmp("after.bmp", bigger_array, 2 * x, 2 * y);
    free(bigger_array);
}

void invert_color(uchar* array, int x, int y){
	// Simple RBG iversion by taking each pixel value and substracting from 255
	for (int i=0; i<y; i++ ) { // To iterate through rows
		for (int j=0; j<x*3; j+=3) { // To iterate through columns (and each pixel component)
			array[3 * i * x + j + 0] = 255 - array[3 * i * x + j + 0]; 
			array[3 * i * x + j + 1] = 255 - array[3 * i * x + j + 1]; 
			array[3 * i * x + j + 2] = 255 - array[3 * i * x + j + 2]; 
		}
	}
	savebmp("after.bmp", array, x, y);
}
