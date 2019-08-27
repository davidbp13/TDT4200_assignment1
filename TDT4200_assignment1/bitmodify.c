#include "bitmap.h"	// Tu use uchar type
#include "bitmodify.h"

uchar* resize(uchar* array, int x, int y){
	uchar resized_image [2 * x * y * 3]; // Array  with space an image twice as big
	for (int i=0; i<y; i++ ) { // To iterate through colums
		for (int j=0; j<x*3; j+=3) { // To iterate through rows
			//Fills current pixel in new image
			resized_image[3 * i * x + j + 0] = array[3 * i * x + j + 0];
			resized_image[3 * i * x + j + 1] = array[3 * i * x + j + 1];
			resized_image[3 * i * x + j + 2] = array[3 * i * x + j + 2];
			//Fills right pixel in new image
			resized_image[3 * (i+1) * x + j + 0] = array[3 * i * x + j + 0];
			resized_image[3 * (i+1) * x + j + 1] = array[3 * i * x + j + 1];
			resized_image[3 * (i+1) * x + j + 2] = array[3 * i * x + j + 2];
			//Fills lower pixel in new image
			resized_image[3  * x + (j+1) + 0] = array[3 * i * x + j + 0];
			resized_image[3  * x + (j+1) + 1] = array[3 * i * x + j + 1];
			resized_image[3  * x + (j+1) + 2] = array[3 * i * x + j + 2];
			//Fills right lower pixel in new image
			resized_image[3 * (i+1) * x + (j+1) + 0] = array[3 * i * x + j + 0];
			resized_image[3 * (i+1) * x + (j+1) + 1] = array[3 * i * x + j + 1];
			resized_image[3 * (i+1) * x + (j+1) + 2] = array[3 * i * x + j + 2];
		}
	}
	return resized_image;
}

void invert_color(uchar* array, int x, int y){
	for (int i=0; i<y; i++ ) { // To iterate through colums
		for (int j=0; j<x*3; j+=3) { // To iterate through rows
			// Simple RBG iversion by taking the pixel value and substracting from 255
			array[3 * i * x + j + 0] = 255 - array[3 * i * x + j + 0];
			array[3 * i * x + j + 1] = 255 - array[3 * i * x + j + 1];
			array[3 * i * x + j + 2] = 255 - array[3 * i * x + j + 2];
		}
	}
}
