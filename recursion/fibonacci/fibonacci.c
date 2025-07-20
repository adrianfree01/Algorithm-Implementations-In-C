#include <stdio.h>

int fibonacci(int n)
{
	if(n > 2)
		return fibonacci(n - 1) + fibonacci(n - 2);
	else 
		return n-1;
}

int main()
{
	printf("fibonacci 1: %d\n", fibonacci(1));
	printf("fibonacci 2: %d\n", fibonacci(2));
	printf("fibonacci 3: %d\n", fibonacci(3));
	printf("fibonacci 4: %d\n", fibonacci(4));
	printf("fibonacci 5: %d\n", fibonacci(5));
	printf("fibonacci 6: %d\n", fibonacci(6));
	printf("fibonacci 7: %d\n", fibonacci(7));
	printf("fibonacci 8: %d\n", fibonacci(8));
}