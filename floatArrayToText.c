/*Program to write to equal-sized numerical arrays 'x' and 'y'
 * to a two-column text file named 'filename'
 * The first column of the file contains values from an 'x' array
 * with a given precision 'xprecision', the second --values from
 * 'y' array with 'yprecision'
 * Link to Problem: http://rosettacode.org/wiki/Write_float_arrays_to_a_text_file
 */
//AUTHOR: rapteon; DATE: 17th April 2020

#include<stdio.h>
#include<stdlib.h>

void getArray(float *, int *);
void storeArrays(float *, float *, int *, int *, FILE *, int *);

int main(int argc, char**argv){
	if(argc != 2){
		printf("Invalid number of arguments.\n");
		exit(1);
	}
	else{
		int arraySize, xPrec, yPrec;
		float *xArray, *yArray;
		char* filename = argv[1];
		FILE *fp = fopen(filename, "w");

		if(!fp){
			ferror(fp);
			exit(2);
		}
		else{
			printf("Array Size: ");
			scanf("%d", &arraySize);
			xArray = (float*)calloc(arraySize, sizeof(float));
			yArray = (float*)calloc(arraySize, sizeof(float));
			printf("x-array\nPrecision:: ");
			scanf("%d", &xPrec);
			getArray(xArray, &arraySize);
			printf("y-array\nPrecision:: ");
			scanf("%d", &yPrec);
			getArray(yArray, &arraySize);
			storeArrays(xArray, yArray, &xPrec, &yPrec, fp, &arraySize);
			fclose(fp);
		}
	}
}

void getArray(float *array, int *size){		
	for(int i = 0; i < *size; i++){
		printf("Element:%d: ", i);
		scanf("%f", &array[i]);
	}
}

void storeArrays(float *array_1, float *array_2, int *array_1_prec, int *array_2_prec, FILE* fp, int *size){
	for(int i = 0; i < *size; i++)
		fprintf(fp, "%.*f\t%.*f\n", *array_1_prec, array_1[i],*array_2_prec, array_2[i]);
}	
