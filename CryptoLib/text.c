#include <stdio.h>
#include <math.h>

int gcd(int a, int b);

int main() {

	int n = 157;
	int smallest = 3;
	int b = 1;
	int ferm_witn = 0;
	int i = 2;
	while (i < n-1)
	{
		// Modular exponentiation.
		int a = 0;
	
		for (int j = 0; j < n-1; ++j)
		{
			a = (i * b)%n;
			b = a;
		}
			
		if (a != 1)
		{
			ferm_witn = i;
			break;
		}
		else
			++i;
	}
	
	
	if (ferm_witn != 0)
	{
		printf("p = %d is not a prime \n", n);
		printf("Smallest fermat witness is  %d \n", ferm_witn);
	}
	else
	{
		printf("p = %d is a prime number \n", n);
	}
	
	return 0;

}

int gcd(int a, int b) {
	int q, r;
	do {
		q = (a - (a%b))/b;
		r = a%b;
		a = b;
		b = r;
	} while (r!=0);
	
	return a;
}
