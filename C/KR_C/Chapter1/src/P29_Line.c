/*------------------------------------------------------------------------
 *
 * P29_Line.c: Write a program that returns one line at a time.
 *
 * COMPILE:
 *   To compile on VC++:
 *         cl.exe /EHsc /W4 P29_Line.c
 *            EHsc -->standard exception handling
 *            W4 is for enabling warning
 *   To compile on gcc:
 *            gcc -Wall -g -o P29_Line P29_Line.c
 *            Wall for enable all Warning
 *            g for debug information
 *
 * EXECUTE:
 *   On Windows, in the command prompt window, type
 *      P29_Line.exe
 *   On Unix, in the shell terminal window, type
 *      ./P29_Line
 *
 *-------------------------------------------------------------------------*/
#include <stdio.h>
#define            LINE_BUF_LENGTH    8

static int getLine(char *buf, size_t line_len) {
	int ch;
	int i = 0;

	for (i = 0; i < line_len - 1 && (ch = getchar()) != EOF && ch != '\n'; ++i)
		buf[i] = ch;

	if (ch == '\n')
		buf[i++] = ch;

	buf[i] = '\0';

	return i;
}

/*-------------------------------------------------------------------------*/

int main() {
	char buf[LINE_BUF_LENGTH];

	while (getLine(buf, LINE_BUF_LENGTH) > 0)
		printf("%s\n", buf);

	return 0;
}

/*-------------------------------------------------------------------------*/
