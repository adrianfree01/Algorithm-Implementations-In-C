#include <stdio.h>

int power(int n, int p)
{
	if(p == 0)
		return 1;
	return n * power(n, p - 1);
}

int main()
{
	printf("5^2 : %d\n", power(5, 2));
	printf("5^3 : %d\n", power(5, 3));
	printf("5^4 : %d\n", power(5, 4));
	printf("5^5 : %d\n", power(5, 5));
	printf("5^6 : %d\n", power(5, 6));
	printf("5^7 : %d\n", power(5, 7));

}