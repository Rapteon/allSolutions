/*
 * Problem:
 * If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
 * Find the sum of all the multiples of 3 or 5 below 1000.
 *
 * Source: https://projecteuler.net/problem=1
 */

#include<stdio.h>

int main(){
	int testCases;		//Number of test cases.
	scanf(" %d", &testCases);
	for(int i = 0; i < testCases; i++){
		int n;		//Maximum limit to test. All multiples of 3 or below this number must be considered.
		scanf("%d", &n);
		int sum = 0;
		//The algorithm involves adding all the multiples of 3 and 5 each and subtracting the sum of multiples of both 3 and 5 (i.e. 15).
		sum = (n%3==0)?(3*(n/3-1)*(n/3))/2:(3*(n/3)*(n/3+1))/2;		//If 3 divides n, then the equation changes.
		sum += (n%5==0)?(5*(n/5-1)*(n/5))/2:(5*(n/5)*(n/5+1))/2;	//If 5 divides n, then the equation changes.
		sum -= (n%15==0)?(15*(n/15-1)*(n/15))/2:(15*(n/15)*(n/15+1))/2;	//If 15 divides n, then the equation changes.
		printf("%d\n", sum);
	}
}
