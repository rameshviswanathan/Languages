/*------------------------------------------------------------------------
 *
 * P71_Ex_1_StrrIndex.c: Write the function strindex(s,t) which
 * returns the position of the rightmost occurrence of t in s, or -1 if
 * there is none.
 *
 * COMPILE:
 *   To compile on VC++:
 *         cl.exe /EHsc /W4 P71_Ex_1_StrrIndex.c
 *            EHsc -->standard exception handling
 *            W4 is for enabling warning
 *   To compile on gcc:
 *            gcc -Wall -g -o P71_Ex_1_StrrIndex P71_Ex_1_StrrIndex.c
 *            Wall for enable all Warning
 *            g for debug information
 *
 * EXECUTE:
 *   On Windows, in the command prompt window, type
 *      P71_Ex_1_StrrIndex.exe
 *   On Unix, in the shell terminal window, type
 *      ./P71_Ex_1_StrrIndex
 *
 *-------------------------------------------------------------------------*/
#include <stdio.h>
#define BUF_SIZE 40

int strrIndex(char *line, char *search) {
	int lineLen = 0;
	int searchLen = 0;
	int i, j;

	while (line[lineLen])
		++lineLen;

	while (search[searchLen])
		++searchLen;

	for (int i = lineLen - 1; i >= 0; --i) {
		int k;
		for (j = searchLen - 1, k = i; j >= 0 && k >= 0 && search[j] == line[k]; --j, --k)
			;

		if (j + 1 == 0)
			return k + 1;
	}
	return -1;
}

/*-------------------------------------------------------------------------*/

int main(void) {
	char line[BUF_SIZE] = "abcdefabcghiabcuioiu";
	char search[BUF_SIZE] = "abc";
	int rIdx = 0;

	rIdx = strrIndex(line, search);

	if (rIdx >= 0)
		printf("The index is at %d\n", rIdx);
	else
		printf("Not found\n");

	return 0;
}

/*-------------------------------------------------------------------------*/
