/*------------------------------------------------------------------------
 *
 * P69_Grep.c: Write a program that prints all lines that has a
 * specific search word.
 *
 * COMPILE:
 *   To compile on VC++:
 *         cl.exe /EHsc /W4 P69_Grep.c
 *            EHsc -->standard exception handling
 *            W4 is for enabling warning
 *   To compile on gcc:
 *            gcc -Wall -g -o P69_Grep P69_Grep.c
 *            Wall for enable all Warning
 *            g for debug information
 *
 * EXECUTE:
 *   On Windows, in the command prompt window, type
 *      P69_Grep.exe
 *   On Unix, in the shell terminal window, type
 *      ./P69_Grep
 *
 *-------------------------------------------------------------------------*/
#include <stdio.h>
#define BUF_SIZE		60

int GetLine(char *buf, int len) {
	int ch;
	int i;

	for (i = 0; i < len - 1 && (ch = getchar()) != EOF && ch != '\n'; ++i)
		buf[i] = ch;

	if (ch == '\n')
		buf[i++] = ch;

	buf[i] = '\0';

	return i;
}

/*-------------------------------------------------------------------------*/
int strindex(char line[], char search[]) {
	int i;
	int j, k;

	for (i = 0; line[i] != '\0'; ++i) {
		for (j = i, k = 0; line[j] != '\0' && search[k] != '\0' && line[j] == search[k]; ++j, ++k)
			;
		if (k > 0 && search[k] == '\0')
			return i;
	}
	return -1;
}

/*-------------------------------------------------------------------------*/

int main(void) {
	char buf[BUF_SIZE];
	char search[BUF_SIZE] = "char";
	int found = 0;

	while (GetLine(buf, BUF_SIZE)) {
		if (strindex(buf, search) >= 0) {
			printf("%s\n", buf);
			found++;
		}
	}

	printf("Total number of lines: %d\n", found);

	return 0;
}

/*-------------------------------------------------------------------------*/
