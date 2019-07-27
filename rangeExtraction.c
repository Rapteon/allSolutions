/*Program to extract range of numbers from an array; AUTHOR:rapteon; DATE: 2019-07-27*/

#include<stdio.h>

void rangeExtractor(int *pos, int size){	
	int count = 0, initialPosition = 0, currentPosition = 0, distance = 0;		
	//`distance` refers to the distance number of spaces between 2 integers. Example: In the array {1, 2, 3}, the distance between 1 and 3 is 2.
	//Also, `distance` must be greater than 1 for a range to be specified
	//The variable `initialPosition` is used to denote the index of the first set of subsequent numbers in the set.
	int copyOfArray[size];

//Creating a copy of the given array
	for(int i = 0; i < size; i++)
		copyOfArray[i] = *(pos+i);

//the `while` loop continues till the value of count is equal to size-1. This is because the value of count starts with 0, and so does the index of the array

	while(count < size-1){
		if(copyOfArray[currentPosition+1] == copyOfArray[currentPosition] + 1){
			/*If every n+1th element's value differs from the nth elements value by 1, then move onto the next position*/
			currentPosition++;
			distance++;

		}
		else if(distance>1){
			printf("%d-%d,", copyOfArray[initialPosition], copyOfArray[currentPosition]);
			/*The initialPosition changes to the value after the current position since we know that the currentPosition is not contiguous with 				the next.*/
			initialPosition = currentPosition+1;
			/*`count` is increased by the value of `distance` since `distance` measures the number of spaces, which also means the position 			moved*/
			count+=distance;
			/*`distance` is set to 0 since the distance between multiple sets of sequential elements must be measured*/
			distance = 0;

		}
		else{
			/*This `else` runs when there is no element which differs from the previous element by 1 and distance is less than 1*/
			/*We print the value at the index `currentPosition+1` since we know that the element at currentPosition+1 differs from the previous 				element by more than 1*/
			printf("%d,", copyOfArray[currentPosition+1]);
			currentPosition++;
			/*We set the intialPosition to be currentPosition+1 since we know that there is (no range possible in the current case) or (a new 				range may start with the next element*/ 
			initialPosition = currentPosition+1;
			count++;
			
		}
	}

	printf("\nDone\n");	
}

int main(){
	int array[] = {0, 1, 2, 4, 6, 7, 8, 11, 12, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 27, 28, 29, 30, 31, 32, 33, 35, 36, 37, 38, 39, 41, 42, 43};
	int initialPosition = 0, currentPosition = 0, distance = 0;

	rangeExtractor(&array[0], 36);
}

