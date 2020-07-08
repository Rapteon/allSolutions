//Source: The Art of Computer Programming(Volume-1, edition-3)
/*
	Given two positive integers 'm' and 'n',
	compute their greatest common divisor 'd', such that
	we also compute two not-necessarily-positive
	integers 'a' and 'b' such that am + bn = d.
*/

#include<stdio.h>

void extended_gcd(int, int);

//'a_prime' and 'b_prime' are auxilliary variables.
static int a_prime = 1, b_prime = 0, a = 0, b = 1, c, d;

int main(){
	extended_gcd(26,16);	
	return 0;
}

void extended_gcd(int m, int n){
	int q, r, t;
	if(m < n){
		t = m;
		m = n;
		n = t;
	}
	c = m;
	d = n;
	while(c % d != 0){
		q = c / d;
		r = c % d;
		c = d;
		d = r;
		
		//Changes to a and a_prime
		t = a_prime;
		a_prime = a;
		a = t - a*q;

		//Changes to b and b_prime
		t = b_prime;
		b_prime = b;
		b = t - b*q;		
	}
	printf("GCD(%d,%d) = %d\n", m, n, d);
	printf("a = %d\nb = %d\n", a, b);
}
