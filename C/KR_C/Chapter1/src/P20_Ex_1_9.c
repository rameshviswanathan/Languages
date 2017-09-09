/*------------------------------------------------------------------------
 *
 * P18_Ex_1_9.c: Write a program to copy its input to its output,
 * replacing each tab by ]t, each backspace by \b, and each backslash by
 * \\.  This makes tabs and backspaces visibile in an unambiguous way.
 *
 * COMPILE:
 *   To compile on VC++:
 *         cl.exe /EHsc /W4 P18_Ex_1_9.c
 *            EHsc -->standard exception handling
 *            W4 is for enabling warning
 *   To compile on gcc:
 *            gcc -Wall -g -o P18_Ex_1_9 P18_Ex_1_9.c
 *            Wall for enable all Warning
 *            g for debug information
 *
 * EXECUTE:
 *   On Windows, in the command prompt window, type
 *      P18_Ex_1_9.exe
 *   On Unix, in the shell terminal window, type
 *      ./P18_Ex_1_9
 *
 *-------------------------------------------------------------------------*/
#include <stdio.h>

int main() {
	int ch;

	while ((ch = getchar()) != EOF) {
		if (ch == ' ') {
			putchar('\\');
			putchar('b');
		}
		else if (ch == '\t') {
			putchar('\\');
			putchar('t');
		}
		else if (ch == '\b') {
			putchar('\\');
			putchar('\\');
		}
		else
			putchar(ch);
	}

	return 0;
}

/*-------------------------------------------------------------------------*/
