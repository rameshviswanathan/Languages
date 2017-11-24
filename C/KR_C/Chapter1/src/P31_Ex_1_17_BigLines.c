/*------------------------------------------------------------------------
 *
 * P31_Ex_1_17_BigLines.c: Write a program to print all input lines
 * that are longer than 80 characters.
 *
 * COMPILE:
 *   To compile on VC++:
 *         cl.exe /EHsc /W4 P31_Ex_1_17_BigLines.c
 *            EHsc -->standard exception handling
 *            W4 is for enabling warning
 *   To compile on gcc:
 *            gcc -Wall -g -o P31_Ex_1_17_BigLines P31_Ex_1_17_BigLines.c
 *            Wall for enable all Warning
 *            g for debug information
 *
 * EXECUTE:
 *   On Windows, in the command prompt window, type
 *      P31_Ex_1_17_BigLines.exe
 *   On Unix, in the shell terminal window, type
 *      ./P31_Ex_1_17_BigLines
 *
 *-------------------------------------------------------------------------*/
#include <stdio.h>
#define BUF_LEN		100
#define BIG_LINE_LEN 50

int getLine(char *buf, int len)
{
	int ch;
	int i;

	for (i = 0; i < len - 1 && (ch = getchar()) != EOF && ch != '\n'; ++i) {
		buf[i] = ch;
	}

	if (ch == '\n')
		buf[i++] = ch;

	buf[i] = '\0';

	return i;
}

/*-------------------------------------------------------------------------*/

int main(void) {
	char line[BUF_LEN];
	int len;

	while ((len = getLine(line, BUF_LEN)) > 0)
		if(len > BIG_LINE_LEN)
			printf("%s\n", line);

	return 0;
}
/*-------------------------------------------------------------------------*/
