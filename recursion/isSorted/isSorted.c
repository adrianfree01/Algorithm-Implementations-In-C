#include <stdio.h>

int isSorted(int arr[], int n)
{
	if(n < 2 && n >= 0)
		return 1;

	if(arr[0] < arr[1] && isSorted(arr+1, n-1))
		return 1;
	return 0;
}

int main()
{
	int arrUnsorted[5] = {3, 2, 1, 4, 5};
	int arrSorted[5] = {1, 2, 3, 4, 5};
	int n = 5;

	printf("Unsorted: %d\n", isSorted(arrUnsorted, n));
	printf("Sorted: %d\n", isSorted(arrSorted, n));
}