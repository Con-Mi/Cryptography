#include <stdio.h>

int gcd(int a, int b);

int main() {

	int a = gcd(36, 17);
	int eulPhi = 0;
		
	for (int i = 1; i < 36; ++i)
	{
		if (gcd(36, i) == 1)
			++eulPhi;
	}	
	
	printf("EPhi(36) = %d \n", eulPhi);
	
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
