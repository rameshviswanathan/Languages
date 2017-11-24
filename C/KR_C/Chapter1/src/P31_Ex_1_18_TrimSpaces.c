/*------------------------------------------------------------------------
 *
 * P31_Ex_1_18_TrimSpaces.c: Write a program to remove trailing blanks
 * and tabs from each line of input, and to delete the entire lines.
 *
 * COMPILE:
 *   To compile on VC++:
 *         cl.exe /EHsc /W4 P31_Ex_1_18_TrimSpaces.c
 *            EHsc -->standard exception handling
 *            W4 is for enabling warning
 *   To compile on gcc:
 *            gcc -Wall -g -o P31_Ex_1_18_TrimSpaces P31_Ex_1_18_TrimSpaces.c
 *            Wall for enable all Warning
 *            g for debug information
 *
 * EXECUTE:
 *   On Windows, in the command prompt window, type
 *      P31_Ex_1_18_TrimSpaces.exe
 *   On Unix, in the shell terminal window, type
 *      ./P31_Ex_1_18_TrimSpaces
 *
 *-------------------------------------------------------------------------*/
#include <stdio.h>

#define BUF_LEN			100

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

int trim(char *line, int len) {

	int isNewLine = 0;
	int i;

	// moving to last character
	len--;

	if (line[len] == '\n') {
		len--;
		isNewLine = 1;
	}

	while (len >= 0 && (line[len] == ' ' || line[len] == '\t'))
		--len;

	// move to next character after non-blank character
	++len;

	// put back new line provided there are non-blank character
	if (len != 0 && isNewLine)
		line[len++] = '\n';

	line[len] = '\0';

	return len;

}

/*-------------------------------------------------------------------------*/
int main(void) {
	char buf[BUF_LEN];
	int len;

	while ((len = getLine(buf, BUF_LEN)) > 0) {
		printf("before Trimming: length is %d \n", len);
		printf("line: %s\n", buf);
		len = trim(buf, len);
		printf("after Trimming: length is %d \n", len);
		printf("line: %s\n", buf);
	}
}

/*-------------------------------------------------------------------------*/
