/*Problem:
 * Using USet, implement a Bag.
 * A Bag is like a USet-it supports the add(x),
 * remove(x) and find(x) methods-but it allows duplicate elements to be stored.
 * The find(x) operation in a Bag returns some element(if any) that is equal to x.
 * In addition, a Bag supports the find_all(x) operation that returns a list of
 * all elements in the Bag that are equal to x.
 */
//AUTHOR: rapteon; DATE: 16th April 2020

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct bag Bag;

void add(int, Bag*);
void delete(int, Bag*);
int find(int, Bag*);
int* find_all(int, Bag*);
int size(Bag*);

void initBagStorage(Bag*);
void showBag(Bag*);
int getInput(void);

struct bag{
	int* storage;
	int itemCount, bagSize;
};

int main(void){
	int choice = 1, num;
	int *foundElements = NULL; 
	Bag* myBag;
	initBagStorage(myBag);
	
	while(1){
		printf("\nOperations:\n");
		printf("1\tadd(x)\n");
		printf("2\tdelete(x)\n");
		printf("3\tfind(x)\n");
		printf("4\tfind_all(x)\n");
		printf("5\tsize()\n");
		printf("6\tSee the Bag\n");
		printf("[1/2/3/4/5/6]: ");
		scanf("%d", &choice);
		switch(choice){
			case 1:	add(getInput(), myBag);
				break;
			case 2:	delete(getInput(), myBag);
				break;
			case 3:	num = find(getInput(), myBag);
				num ? printf("Found: %d\n",num):printf("Not found.\n"); 
				break;
			case 4:	foundElements = find_all(getInput(), myBag);
				printf("Found the following:\n");
				for(int i = 0; i < size(myBag); i++)
					printf("%d ", foundElements[i]);
				printf("\n");
				break;
			case 5:	printf("Size of Bag: %d\n", size(myBag));
			case 6:
				showBag(myBag);
				break;
			default:
				printf("Option is absent. Please retry.\n");
		}
	}
}

void initBagStorage(Bag* b){
	printf("BagSize: ");
	scanf("%d%*c", &b->bagSize);
	b->storage = malloc(sizeof(int)*b->bagSize);
	b->itemCount = 0;
}

void showBag(Bag* b){
	for(int i = 0; i < b->bagSize; i++)
		printf("%d ", *(b->storage+i));
	printf("\n");
}

int getInput(){
	int num;
	printf("Number: ");
	scanf("%d%*c", &num);
	return num;
}
void add(int x, Bag* b){
	if(!x){
		printf("Cannot add 0\n");
		return;
	}
	if(b->itemCount == b->bagSize){
		printf("Bag is full.\n");
		return;
	}
	for(unsigned short i = 0; i < b->bagSize; i++)
		if(b->storage[i] == 0){
			b->storage[i] = x;
			b->itemCount++;
			break;
		}
}
void delete(int x, Bag* b){
	for(unsigned short i = 0; i < b->bagSize; i++)
		if(*(b->storage+i) == x){
			*(b->storage+i) = 0;
			b->itemCount--;
			printf("Deleted %d\n", x);
		}
}
int find(int x, Bag* b){
	bool found = false;
	for(unsigned short i = 0; i < b->bagSize; i++)
		if(x == b->storage[i])
			return b->storage[i];
	if(!found)
		return 0;
}
int* find_all(int x, Bag* b){
	int *toReturn = (int*)malloc(sizeof(int)*b->itemCount);
	unsigned short count = 0;
	for(int i = 0; i < b->itemCount; i++)
		if(b->storage[i] == 0)
			i--;
		else if(x == b->storage[i])
			toReturn[count++] = x;
	return toReturn;
}
int size(Bag* b){
	return b->itemCount;
}