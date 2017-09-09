/*------------------------------------------------------------------------
 *
 * P18_Ex_1_8_c: Write a program to count blanks, tabs, and newlines.
 *
 * COMPILE:
 *   To compile on VC++:
 *         cl.exe /EHsc /W4 P18_Ex_1_8_c.c
 *            EHsc -->standard exception handling 
 *            W4 is for enabling warning
 *   To compile on gcc:
 *            gcc -Wall -g -o P18_Ex_1_8_c P18_Ex_1_8_c.c
 *            Wall for enable all Warning
 *            g for debug information
 *
 * EXECUTE:
 *   On Windows, in the command prompt window, type
 *      P18_Ex_1_8_c.exe
 *   On Unix, in the shell terminal window, type 
 *      ./P18_Ex_1_8_c
 *
 *-------------------------------------------------------------------------*/
#include <stdio.h>

int main()
{
	int nBlank = 0;
	int nNewLine = 0;
	int nTab = 0;

	int ch;

	while ((ch = getchar()) != EOF) {
		if (ch == ' ')
			++nBlank;
		else if (ch == '\t')
			++nTab;
		else if (ch == '\n')
			++nNewLine;
	}

	printf("Blank count: %d\n", nBlank);
	printf("Tab count: %d\n", nTab);
	printf("NewLine count: %d\n", nNewLine);

	return 0;
}

/*-------------------------------------------------------------------------*/
