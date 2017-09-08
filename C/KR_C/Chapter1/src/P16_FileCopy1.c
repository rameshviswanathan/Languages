/*------------------------------------------------------------------------
 *
 * P16_FileCopy1.c: Write a program to copy its input to its output
 * one character at a time
 *
 * COMPILE:
 *   To compile on VC++:
 *         cl.exe /EHsc /W4 P16_FileCopy1.c
 *            EHsc -->standard exception handling
 *            W4 is for enabling warning
 *   To compile on gcc:
 *            gcc -Wall -g -o P16_FileCopy1 P16_FileCopy1.c
 *            Wall for enable all Warning
 *            g for debug information
 *
 * EXECUTE:
 *   On Windows, in the command prompt window, type
 *      P16_FileCopy1.exe
 *   On Unix, in the shell terminal window, type
 *      ./P16_FileCopy1
 *
 *-------------------------------------------------------------------------*/
 /* algorithm
	 read a character from input stream
	 while( read char is not EOF)
		 output read char to output stream
		 read next char from input stream
 */

#include <stdio.h>
int main() {
	int ch;

	ch = getchar();

	while (ch != EOF) {
		putchar(ch);
		ch = getchar();
	}

	return 0;
}

/*-------------------------------------------------------------------------*/
