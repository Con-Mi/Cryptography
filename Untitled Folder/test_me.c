#include <stdio.h>

int main() {
	
	int n = 1105;
	int b = 1;
	int a = 0;
	int k = 5;
	int smallest = 3;
	int ferm_idx = 0;
	// Modular exponentiation.
	for (int i = 0; i < n-1; ++i)
	{
		a = (k * b)%n;
		b  = a;
	}
	printf("%d \n", a);
	
	if (a != 1)
	{
		if (k <= smallest)
		{
			smallest = k;
			printf("%d \n", a);
		}
		++ferm_idx;
		//printf("%d \n", i);
	}
	
	if (ferm_idx == 0)
	{
		printf("p = %d is a prime\n", n);
	}
	else
	{
		printf("p = %d is not a prime\n", n);
		printf("smallest witness of compositeness is %d \n", smallest);
	}

	return 0;
}
