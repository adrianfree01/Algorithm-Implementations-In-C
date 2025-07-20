#include <stdio.h>

int tile(int n)
{
	if(n == 0)
		return 0;
	if(n < 4)
		return 1;
	return 2 + tile(n - 4);
}

int main()
{
	printf("%d\n", tile(4));
	printf("%d\n", tile(5));
	printf("%d\n", tile(6));
	printf("%d\n", tile(7));
	printf("%d\n", tile(8));
}
