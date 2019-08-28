#include "bitmap.h"	// Tu use uchar type
#include "bitmodify.h"
#include <stdio.h>

void resize(uchar* array, uchar* bigger_array, int x, int y){
	for (int i=0; i<y; i++ ) { // To iterate through colums
		for (int j=0; j<x*3; j+=3) { // To iterate through rows
			//Fills current pixel in new image
			bigger_array[3 * i * x + j + 0] = array[3 * i * x + j + 0];
			bigger_array[3 * i * x + j + 1] = array[3 * i * x + j + 1];
			bigger_array[3 * i * x + j + 2] = array[3 * i * x + j + 2];
			//Fills right pixel in new image
			bigger_array[3 * i * x + j + 0 + 1] = array[3 * i * x + j + 0];
			bigger_array[3 * i * x + j + 1 + 1] = array[3 * i * x + j + 1];
			bigger_array[3 * i * x + j + 2 + 1] = array[3 * i * x + j + 2];
			//Fills lower pixel in new image
			bigger_array[3 * i * (x+1) + j + 0 + x] = array[3 * i * x + j + 0];
			bigger_array[3 * i * (x+1) + j + 1 + x] = array[3 * i * x + j + 1];
			bigger_array[3 * i * (x+1) + j + 2 + x] = array[3 * i * x + j + 2];
			//Fills right lower pixel in new image
			bigger_array[3 * (i+1) * (x+1) + j + 0 + x + 1] = array[3 * i * x + j + 0];
			bigger_array[3 * (i+1) * (x+1) + j + 1 + x + 1] = array[3 * i * x + j + 1];
			bigger_array[3 * (i+1) * (x+1) + j + 2 + x + 1] = array[3 * i * x + j + 2];
			//printf("i=%d, j=%d",i,j);
		}
	}
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
