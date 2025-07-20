#include <stdio.h>

int factorial(int k)
{
	if (k > 0)
		return k * factorial(k-1);
	else
		return 1;
}

int main()
{
	printf("Factorial 5: %d\n", factorial(5));
	printf("Factorial 4: %d\n", factorial(4));
	printf("Factorial 3: %d\n", factorial(3));
	printf("Factorial 2: %d\n", factorial(2));
	printf("Factorial 1: %d\n", factorial(1));
	printf("Factorial 0: %d\n", factorial(0));
}