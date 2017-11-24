/*------------------------------------------------------------------------
 *
 * P31_Ex_1_19_Reverse.c: Write a function reverse(s) that reverses
 * the character string s.  Use it to write a program that reverses its
 * input a line at a time.
 *
 * COMPILE:
 *   To compile on VC++:
 *         cl.exe /EHsc /W4 P31_Ex_1_19_Reverse.c
 *            EHsc -->standard exception handling
 *            W4 is for enabling warning
 *   To compile on gcc:
 *            gcc -Wall -g -o P31_Ex_1_19_Reverse P31_Ex_1_19_Reverse.c
 *            Wall for enable all Warning
 *            g for debug information
 *
 * EXECUTE:
 *   On Windows, in the command prompt window, type
 *      P31_Ex_1_19_Reverse.exe
 *   On Unix, in the shell terminal window, type
 *      ./P31_Ex_1_19_Reverse
 *
 *-------------------------------------------------------------------------*/
#include <stdio.h>
#define BUF_LEN       80

void reverse(char *line) {
	int len = 0;
	int i, j;

	while (line[len] != '\0')
		++len;

	for (i = 0, j = len - 1; i < j; ++i, --j) {
		char temp = line[i];
		line[i] = line[j];
		line[j] = temp;
	}
}

/*-------------------------------------------------------------------------*/
int getLine(char *buf, int len) {
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

int main(void) {
	char buf[BUF_LEN];
	int len;

	while ((len = getLine(buf, BUF_LEN)) > 0) {
		printf("unreversed: %s\n", buf);
		reverse(buf);
		printf("reversed  : %s\n", buf);
	}

	return 0;
}

/*-------------------------------------------------------------------------*/
