/*------------------------------------------------------------------------
 *
 * P58_Ex_3_1_BinarySearch.c: Our binary search makes two tests inside
 * the loop, when one would suffice (at the price of more tests outside.)
 * Write a version with only one test inside the loop and measure the
 * difference in run-time.
 *
 * COMPILE:
 *   To compile on VC++:
 *         cl.exe /EHsc /W4 P58_Ex_3_1_BinarySearch.c
 *            EHsc -->standard exception handling
 *            W4 is for enabling warning
 *   To compile on gcc:
 *            gcc -Wall -g -o P58_Ex_3_1_BinarySearch P58_Ex_3_1_BinarySearch.c
 *            Wall for enable all Warning
 *            g for debug information
 *
 * EXECUTE:
 *   On Windows, in the command prompt window, type
 *      P58_Ex_3_1_BinarySearch.exe
 *   On Unix, in the shell terminal window, type
 *      ./P58_Ex_3_1_BinarySearch
 *
 *-------------------------------------------------------------------------*/
#include <stdio.h>

int BinSearch(int searchVal, int arr[], int len) {
	int lower, upper;
	lower = 0;
	upper = len - 1;
	int mid = (lower + upper) >> 1;
	int retVal = -1;

	while (lower <= upper && searchVal != arr[mid]) {
		if (searchVal < arr[mid])
			upper = mid - 1;
		else
			lower = mid + 1;

		mid = (lower + upper) >> 1;
	}

	if (searchVal == arr[mid])
		retVal = mid;

	return retVal;
}

/*-------------------------------------------------------------------------*/

int main(void) {
	int arr[6] = { 8, 16, 24, 32, 40, 48 };
	int len = sizeof(arr) / sizeof(arr[0]);

	int searchValue = 16;
	int index = BinSearch(searchValue, arr, len);
	printf("Index is %d\n", index);

	searchValue = 15;
	index = BinSearch(searchValue, arr, len);
	printf("Index is %d\n", index);

	searchValue = 8;
	index = BinSearch(searchValue, arr, len);
	printf("Index is %d\n", index);

	searchValue = 48;
	index = BinSearch(searchValue, arr, len);
	printf("Index is %d\n", index);

	return 0;
}

/*-------------------------------------------------------------------------*/
