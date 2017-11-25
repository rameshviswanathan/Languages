/*------------------------------------------------------------------------
 *
 * P34_Ex_1_20_Detab.c: Write a program detab that replaces tabs in
 * the input with the proper number of blanks to space to the next tab
 * stop. Assume a fixed set of tab stops, say every n columns. Should n
 * be a variable or a symbolic parameter?
 *
 * COMPILE:
 *   To compile on VC++:
 *         cl.exe /EHsc /W4 P34_Ex_1_20_Detab.c
 *            EHsc -->standard exception handling
 *            W4 is for enabling warning
 *   To compile on gcc:
 *            gcc -Wall -g -o P34_Ex_1_20_Detab P34_Ex_1_20_Detab.c
 *            Wall for enable all Warning
 *            g for debug information
 *
 * EXECUTE:
 *   On Windows, in the command prompt window, type
 *      P34_Ex_1_20_Detab.exe
 *   On Unix, in the shell terminal window, type
 *      ./P34_Ex_1_20_Detab
 *
 *-------------------------------------------------------------------------*/
#include <stdio.h>

#define TAB_SPACE	4

int main(void) {
	int ch;

	while ((ch = getchar()) != EOF) {
		if (ch != '\t')
			putchar(ch);
		else {
			for (int i = 0; i < TAB_SPACE; ++i)
				putchar(' ');
		}
	}
	return 0;
}

/*-------------------------------------------------------------------------*/
