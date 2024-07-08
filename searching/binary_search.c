// C program to implement iterative Binary Search
#include <stdio.h>

// An iterative binary search function.
int binarySearch(int arr[], int l, int h, int x)
{
	while (l <= h) {
		int m = l + (h - l) / 2;

		// Check if x is present at mid
		if (arr[m] == x)
			return m;

		// If x greater, ignore left half
		if (arr[m] < x)
			l = m + 1;

		// If x is smaller, ignore right half
		else
			h = m - 1;
	}

	// If we reach here, then element was not present
	return -1;
}

// Driver code
int main(void)
{
	int arr[] = { 2, 3, 4, 10, 40 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int x = 10;
	int result = binarySearch(arr, 0, n - 1, x);
	if(result == -1) 
    { 
        printf("Element is not present in array");
    }			
    else
    printf("Element is present at index %d",result);
	return 0;
}
