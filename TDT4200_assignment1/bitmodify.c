#include "bitmap.h"	// Tu use uchar type
#include "bitmodify.h"
#include <stdio.h>

void resize(uchar* array, uchar* bigger_array, int x, int y){
	for (int i=0; i<y; i++ ) { // To iterate through colums
		for (int j=0; j<x*3; j+=3) { // To iterate through rows
			//Fills current pixel in new image
			bigger_array[(3 * i * 2*x + j)*2 + 0] = array[3 * i * x + j + 0]; // 3 * i * 2*x since the image is now twice the width and *2 in the end because is twice the height
			bigger_array[(3 * i * 2*x + j)*2 + 1] = array[3 * i * x + j + 1];
			bigger_array[(3 * i * 2*x + j)*2 + 2] = array[3 * i * x + j + 2];
			
			//Fills right pixel in new image
			bigger_array[(3 * i * 2*x + j)*2 + 0 + 3] = array[3 * i * x + j + 0];
			bigger_array[(3 * i * 2*x + j)*2 + 1 + 3] = array[3 * i * x + j + 1];
			bigger_array[(3 * i * 2*x + j)*2 + 2 + 3] = array[3 * i * x + j + 2];
			
			//Fills upper pixel in new image
			bigger_array[(3 * i * 2*x + j)*2 + 2*3*x + 0] = array[3 * i * x + j + 0]; // 2*3*x to jump to upper row
			bigger_array[(3 * i * 2*x + j)*2 + 2*3*x + 1] = array[3 * i * x + j + 1];
			bigger_array[(3 * i * 2*x + j)*2 + 2*3*x + 2] = array[3 * i * x + j + 2];
			
		    //Fills right upper pixel in new image
			bigger_array[(3 * i * 2*x + j)*2 + 2*3*x + 0 + 3] = array[3 * i * x + j + 0];
			bigger_array[(3 * i * 2*x + j)*2 + 2*3*x + 1 + 3] = array[3 * i * x + j + 1];
			bigger_array[(3 * i * 2*x + j)*2 + 2*3*x + 2 + 3] = array[3 * i * x + j + 2];
		}
	}
}

void invert_color(uchar* array, int x, int y){
	for (int i=0; i<y; i++ ) { // To iterate through rows
		for (int j=0; j<x*3; j+=3) { // To iterate through columns (and each pixel component)
			// Simple RBG iversion by taking the pixel value and substracting from 255
			array[3 * i * x + j + 0] = 255 - array[3 * i * x + j + 0]; 
			array[3 * i * x + j + 1] = 255 - array[3 * i * x + j + 1]; 
			array[3 * i * x + j + 2] = 255 - array[3 * i * x + j + 2]; 
		}
	}
}
