#include <stdio.h>
#include <math.h>

int gcd(int a, int b);

int main() {

	int n = 1105;
	int smallest = 3;
	int b = 1;
	int ferm_idx = 0;
		
	for (int i = 2; i < n; ++i)
	{
		int a = 0;
		// Modular exponentiation.
		for (int j = 0; j < (n/15)-1; ++j)
		{	
			a = (i * b) % n;
			b = a;
				printf("%d \n", a);
		}	// End.
		if (a != 1)
		{
			if (i <= smallest)
			{
				smallest = i;
				++ferm_idx;
				printf("%d \n", a);
				
			}
		}
		
	}
	
	if (ferm_idx == 0)
		printf("p = %d is a prime\n", n);
	else
	{
		printf("p = %d is not a prime\n", n);
		printf("smallest witness of compositeness is %d \n", smallest);
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
