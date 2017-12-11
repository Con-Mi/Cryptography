// Compilation (compile the _test file, which includes this file):
//   g++ -o cryptoLib cryptoLib_test.cpp
// Running:
//   ./cryptoLib

#include <stdio.h>
#include <math.h>

/**
 * Assigns to the array "result" the values "result[0] = gcd", "result[1] = s"
 * and "result[2] = t" such that "gcd" is the greatest common divisor of "a" and
 * "b", and "gcd = a * s + b * t".
 **/
void EEA(int a, int b, int result[]) {
	// Special case: a=b
	if (a == b) {
		result[0] = a;
		result[1] = 1;
		result[2] = 0;
		return;
	}
	// Declare variables
	int s, s1, s2, t, t1, t2;
    int gcd = -1;
    int x = 0;
	int x1 = 1;
	int x2 = 0;
    int y = 1;
	int y1 = 0;
	int y2 = 1;
	int quotient, remainder;
	// Swap such that a>b
	if (b > a) {
		a += b;
		b = a - b;
		a -= b;
		// Set t and s variables
		t = y;
		t1 = y1;
		t2 = y2;
		s = x;
		s1 = x1;
		s2 = x2;
	}
	else {
		t = x;
		t1 = x1;
		t2 = x2;
		s = y;
		s1 = y1;
		s2 = y2;
	}

	while (b > 0) {
		quotient = floor(a / b);
		remainder = a - quotient*b;
		// Update t1 and 
		t = t2 - quotient*t1;
		s = s2 - quotient*s1;
		// Update a and b
		a = b;
		b = remainder;
		// Update temporary variables
		s2 = s1;
		t2 = t1;
		t1 = t;
		s1 = s;
	}
	gcd = a;
	s = s2;
	t = t2;
	// Store results
    result[0] = gcd;
    result[1] = s;
    result[2] = t;
}

/**
 * Returns Euler's Totient for value "n".
 **/
int gcd(int a, int b)
{
	int q, r;
	do {
		q = (a - (a%b))/b;
		r = a%b;
		a = b;
		b = r;
	} while (r != 0);
	
	return a;
} 

int EulerPhi(int n){

	int euler_Phi = 0;
	for (int i = 1; i < n; ++i)
	{
		if (gcd(n, i) == 1)
		{
			++euler_Phi;
		}
	}
	return euler_Phi;
}

/**
 * Returns the value "v" such that "n*v = 1 (mod m)".
 * Returns 0 if the modular inverse does not exist.
 **/
int ModInv(int n, int m){
	bool negativeCase = false;
	if (n < 0) {
		n = m - n;
		negativeCase = true;
	}
	// Use extended euclidean algorithm
	int tmpArray[3];
	EEA(n,m,tmpArray);
	// Check if inverse exists
	int gcd = tmpArray[0];
	if (negativeCase)
		tmpArray[1] = m - tmpArray[1];
	if (gcd != 1)
		return 0;
	// Check for negative numbers
	if (tmpArray[1] < 0)
		return (m + tmpArray[1]);
	return tmpArray[1];

}

/**
 * Returns 0 if "n" is a Fermat Prime, otherwise it returns the lowest Fermat
 * Witness. Tests values from 2 (inclusive) to "n/3" (exclusive).
 **/
int FermatPT(int n){

	int i = 2;
	int b = 1;
	int smallest = 0;
	
	while (i < n - 1) {
		// Modular exponentiation.
		int a = 0;
		for (int j = 0; j < n-1; ++j)
		{	
			a = (i * b) % n;
			b = a;
		}	// End.
	
		if (a != 1)
		{
			smallest = i;
			break;
		}
		else	
			++i;
	}
	
	if (smallest == 0)
		return 0;
	else
		return smallest;
}

/**
 * Returns the probability that calling a perfect hash function with "n_samples"
 * (uniformly distributed) will give one collision (i.e. that two samples result
 * in the same hash) -- where "size" is the number of different output values
 * the hash function can produce.
 **/
double HashCP(double n_samples, double size){
	
	double prob = 1.0;
	double tmprVal = size - (n_samples-1.0);
	for (int i = 0; i < n_samples; ++i)
	{
		prob *= tmprVal/size;
		++tmprVal;
	}
	
	return 1 - prob;
}
