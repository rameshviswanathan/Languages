/*------------------------------------------------------------------------
 *
 * P29_MaxLine.c: Write a program that prints the maximum line in the
 * input stream.
 *
 * COMPILE:
 *   To compile on VC++:
 *         cl.exe /EHsc /W4 P29_MaxLine.c
 *            EHsc -->standard exception handling
 *            W4 is for enabling warning
 *   To compile on gcc:
 *            gcc -Wall -g -o P29_MaxLine P29_MaxLine.c
 *            Wall for enable all Warning
 *            g for debug information
 *
 * EXECUTE:
 *   On Windows, in the command prompt window, type
 *      P29_MaxLine.exe
 *   On Unix, in the shell terminal window, type
 *      ./P29_MaxLine
 *
 *-------------------------------------------------------------------------*/

#include <stdio.h>
#define LINE_BUF_SIZE 80

int getLine(char * lineBuf, size_t lineLen) {
	int i = 0;
	int ch;

	for (; i < lineLen - 1 && (ch = getchar()) != EOF && ch != '\n'; ++i)
		lineBuf[i] = ch;

	if (ch == '\n')
		lineBuf[++i] = ch;

	lineBuf[i] = '\0';

	return i;

}

/*-------------------------------------------------------------------------*/

void copy(char *copyTo, char *copyFrom, int maxLength) {
	int i = 0;

	for (; i < maxLength && *copyFrom != '\0'; ++i) {
		*copyTo++ = *copyFrom++;
	}
	*copyTo = '\0';

}

/*-------------------------------------------------------------------------*/

int main() {
	char lineBuf[LINE_BUF_SIZE];
	char maxBuf[LINE_BUF_SIZE];
	int maxLineLength = 0;
	int curLen;

	while ((curLen = getLine(lineBuf, LINE_BUF_SIZE))> 0) {
		if (curLen > maxLineLength) {
			copy(maxBuf, lineBuf, LINE_BUF_SIZE);
			maxLineLength = curLen;
		}
	}

	if (maxLineLength > 0)
		printf("%s\n", maxBuf);

	return 0;
}

/*-------------------------------------------------------------------------*/
