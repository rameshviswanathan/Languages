/*------------------------------------------------------------------------
 *
 * P62_ShellSort.c: Write a program to implement shell sort.
 *
 * COMPILE:
 *   To compile on VC++:
 *         cl.exe /EHsc /W4 P62_ShellSort.c
 *            EHsc -->standard exception handling
 *            W4 is for enabling warning
 *   To compile on gcc:
 *            gcc -Wall -g -o P62_ShellSort P62_ShellSort.c
 *            Wall for enable all Warning
 *            g for debug information
 *
 * EXECUTE:
 *   On Windows, in the command prompt window, type
 *      P62_ShellSort.exe
 *   On Unix, in the shell terminal window, type
 *      ./P62_ShellSort
 *
 *-------------------------------------------------------------------------*/
#include <stdio.h>
#include <assert.h>

void ShellSort(int *arr, int len)
{
	int gap;
	int i;
	int j;

	for (gap = len >> 1; gap > 0; gap >>= 1) {
		for (i = gap; i < len; ++i) {
			for (j = i - gap; j >= 0 && arr[j] > arr[j + gap]; j -= gap) {
				int temp = arr[j];
				arr[j] = arr[j + gap];
				arr[j + gap] = temp;
			}
		}
	}
}

/*-------------------------------------------------------------------------*/
void printArr(int *arr, int size) {
	assert(arr != NULL && size >= 0);

	for (int i = 0; i < size; ++i)
		printf("%d\t", arr[i]);

	printf("\n");
}

/*-------------------------------------------------------------------------*/

int main() {
	int arr[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	int size = sizeof(arr) / sizeof(arr[0]);
	printf("Before : ");
	printArr(arr, size);

	ShellSort(arr, size);

	printf("After  : ");
	printArr(arr, size);

	return 0;
}

/*-------------------------------------------------------------------------*/