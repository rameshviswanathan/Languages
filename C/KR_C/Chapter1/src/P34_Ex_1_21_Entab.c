/*------------------------------------------------------------------------
 *
 * P34_Ex_1_21_Entab.c: Write a program entab that replaces strings of
 * blanks by the minimum number of tabs and blanks to achieve the same
 * spacing. Use the same tab stops as for detab. When either a tab or a
 * single blank would suffice to reach a tab stop, which should be given
 * preference?
 *
 * COMPILE:
 *   To compile on VC++:
 *         cl.exe /EHsc /W4 P34_Ex_1_21_Entab.c
 *            EHsc -->standard exception handling
 *            W4 is for enabling warning
 *   To compile on gcc:
 *            gcc -Wall -g -o P34_Ex_1_21_Entab P34_Ex_1_21_Entab.c
 *            Wall for enable all Warning
 *            g for debug information
 *
 * EXECUTE:
 *   On Windows, in the command prompt window, type
 *      P34_Ex_1_21_Entab.exe
 *   On Unix, in the shell terminal window, type
 *      ./P34_Ex_1_21_Entab
 *
 *-------------------------------------------------------------------------*/
#include <stdio.h>
#define TAB_SPACE	4

int main(void) {
	int ch;
	int cnt = 0;

	while ((ch = getchar()) != EOF) {
		if (ch == ' ') {
			cnt++;
		}
		else {
			while (cnt >= TAB_SPACE) {
				putchar('\t');
				cnt -= TAB_SPACE;
			}

			while (cnt > 0) {
				putchar(' ');
				cnt -= 1;
			}
			putchar(ch);
			cnt = 0;
		}
	}

	return 0;
}

/*-------------------------------------------------------------------------*/
