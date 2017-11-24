/*------------------------------------------------------------------------
 *
 * P32_MaxLine_WithExtVariable.c: Re-write maxline program to use
 * external variable to store lines.
 *
 * COMPILE:
 *   To compile on VC++:
 *         cl.exe /EHsc /W4 P32_MaxLine_WithExtVariable.c
 *            EHsc -->standard exception handling
 *            W4 is for enabling warning
 *   To compile on gcc:
 *            gcc -Wall -g -o P32_MaxLine_WithExtVariable P32_MaxLine_WithExtVariable.c
 *            Wall for enable all Warning
 *            g for debug information
 *
 * EXECUTE:
 *   On Windows, in the command prompt window, type
 *      P32_MaxLine_WithExtVariable.exe
 *   On Unix, in the shell terminal window, type
 *      ./P32_MaxLine_WithExtVariable
 *
 *-------------------------------------------------------------------------*/

#include <stdio.h>
#define LINE_BUF_SIZE 80

char lineBuf[LINE_BUF_SIZE];
char maxBuf[LINE_BUF_SIZE];
int maxLineLength = 0;

int getLine(void) {
	int i = 0;
	int ch;
	extern char lineBuf[];

	for (; i < LINE_BUF_SIZE - 1 && (ch = getchar()) != EOF && ch != '\n'; ++i)
		lineBuf[i] = ch;

	if (ch == '\n')
		lineBuf[++i] = ch;

	lineBuf[i] = '\0';

	return i;
}

/*-------------------------------------------------------------------------*/

void copy(void) {
	int i = 0;
	extern char maxBuf[];
	extern char lineBuf[];

	while ((maxBuf[i] = lineBuf[i]) != '\0')
	++i;
}

/*-------------------------------------------------------------------------*/

int main() {
	int curLen;
	extern int maxLineLength;
	extern char maxBuf[];

	while ((curLen = getLine()) > 0) {
		if (curLen > maxLineLength) {
			copy();
			maxLineLength = curLen;
		}
	}

	if (maxLineLength > 0)
		printf("%s\n", maxBuf);

	return 0;
}

/*-------------------------------------------------------------------------*/
