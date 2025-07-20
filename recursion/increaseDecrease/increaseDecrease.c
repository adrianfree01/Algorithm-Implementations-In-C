#include <stdio.h>

void decrease(int n)
{
	if(n == 0)
		printf("%d\n", 0);
	else
	{
		printf("%d ", n);
		decrease(n - 1);
	}
}

void increase(int n)
{
	if(n == 0)
		printf("%d ", 0);
	else
	{
		increase(n - 1);
		printf("%d ", n);
	}
}

int main()
{
	increase(5);
	printf("\n");
	decrease(5);
}