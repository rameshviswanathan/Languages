/*------------------------------------------------------------------------
 *
 * P58_BinarySearch.c: Write a program that searches for a key in a
 * sorted array.
 *
 * COMPILE:
 *   To compile on VC++:
 *         cl.exe /EHsc /W4 P58_BinarySearch.c
 *            EHsc -->standard exception handling
 *            W4 is for enabling warning
 *   To compile on gcc:
 *            gcc -Wall -g -o P58_BinarySearch P58_BinarySearch.c
 *            Wall for enable all Warning
 *            g for debug information
 *
 * EXECUTE:
 *   On Windows, in the command prompt window, type
 *      P58_BinarySearch.exe
 *   On Unix, in the shell terminal window, type
 *      ./P58_BinarySearch
 *
 *-------------------------------------------------------------------------*/

#include <stdio.h>

int BinSearch(int searchValue, int arr[], int len) {
	int lower, upper;
	lower = 0;
	upper = len - 1;

	while (lower <= upper) {
		int mid = (lower + upper) >> 1;
		if (searchValue < arr[mid])
			upper = mid - 1;
		else if (searchValue > arr[mid])
			lower = mid + 1;
		else
			return mid;
	}

	return -1;
}

/*-------------------------------------------------------------------------*/

int BinSearchRecursive(int searchValue, int arr[], int lower, int upper) {
	int mid = (lower + upper) >> 1;
	int index = -1;
	if (lower <= upper) {
		if (searchValue < arr[mid])
			index = BinSearchRecursive(searchValue, arr, lower, mid - 1);
		else if (searchValue > arr[mid])
			index = BinSearchRecursive(searchValue, arr, mid + 1, upper);
		else
			index = mid;
	}

	return index;
}
/*-------------------------------------------------------------------------*/

int main(void) {
	int arr[6] = { 8, 16, 24, 32, 40, 48 };
	int len = sizeof(arr) / sizeof(arr[0]);

	int searchValue = 16;
	int index = BinSearch(searchValue, arr, len);
	printf("Index is %d\n", index);
	index = BinSearchRecursive(searchValue, arr, 0, len - 1);
	printf("RecursiveIndex is %d\n", index);

	searchValue = 15;
	index = BinSearch(searchValue, arr, len);
	printf("Index is %d\n", index);
	index = BinSearchRecursive(searchValue, arr, 0, len - 1);
	printf("RecursiveIndex is %d\n", index);

	searchValue = 8;
	index = BinSearch(searchValue, arr, len);
	printf("Index is %d\n", index);
	index = BinSearchRecursive(searchValue, arr, 0, len - 1);
	printf("RecursiveIndex is %d\n", index);

	searchValue = 48;
	index = BinSearch(searchValue, arr, len);
	printf("Index is %d\n", index);
	index = BinSearchRecursive(searchValue, arr, 0, len - 1);
	printf("RecursiveIndex is %d\n", index);

	return 0;
}

/*-------------------------------------------------------------------------*/
