/*------------------------------------------------------------------------
 *
 * P21_Ex_1_12.c: Write a program that prints its input one word per
 * line.
 *
 * COMPILE:
 *   To compile on VC++:
 *         cl.exe /EHsc /W4 P21_Ex_1_12.c
 *            EHsc -->standard exception handling
 *            W4 is for enabling warning
 *   To compile on gcc:
 *            gcc -Wall -g -o P21_Ex_1_12 P21_Ex_1_12.c
 *            Wall for enable all Warning
 *            g for debug information
 *
 * EXECUTE:
 *   On Windows, in the command prompt window, type
 *      P21_Ex_1_12.exe
 *   On Unix, in the shell terminal window, type
 *      ./P21_Ex_1_12
 *
 *-------------------------------------------------------------------------*/

 /* Algorithm
 set a variable "insideWord" to track if we are inside word or not
 set InsideWord to FALSE
 while read char is not EOF
	 if read char is space and insideWord is TRUE
		 insert newline
		 set InsideWord to FALSE
	 else
		 print read char
		 set insideWord to TRUE

 */

#define TRUE 1
#define FALSE 0

#include <stdio.h>
#include <ctype.h>

int main() {
	int insideWord = FALSE;

	int ch;

	while ((ch = getchar()) != EOF) {
		if (isspace(ch) && insideWord == TRUE) {
			insideWord = FALSE;
			putchar('\n');
		}
		else {
			insideWord = TRUE;
			putchar(ch);
		}
	}

	return 0;
}

/*-------------------------------------------------------------------------*/
