#include <stdio.h>

int main() {
	
	int n = 1105;
	int b = 1;
	int a = 0;
	int k = 1100;
	// Modular exponentiation.
	for (int i = 0; i < n-1; ++i)
	{
		a = (k * b)%n;
		b  = a;
	}
	printf("%d \n", a);
	

	return 0;
}
