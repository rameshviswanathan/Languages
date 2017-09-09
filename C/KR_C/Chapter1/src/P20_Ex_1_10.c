/*------------------------------------------------------------------------
 *
 * P20_Ex_1_10.c: Write a program to copy its input to its output,
 * replacing string of one or more blanks by a single blank.
 *
 * COMPILE:
 *   To compile on VC++:
 *         cl.exe /EHsc /W4 P20_Ex_1_10.c
 *            EHsc -->standard exception handling
 *            W4 is for enabling warning
 *   To compile on gcc:
 *            gcc -Wall -g -o P20_Ex_1_10 P20_Ex_1_10.c
 *            Wall for enable all Warning
 *            g for debug information
 *
 * EXECUTE:
 *   On Windows, in the command prompt window, type
 *      P20_Ex_1_10.exe
 *   On Unix, in the shell terminal window, type
 *      ./P20_Ex_1_10
 *
 *-------------------------------------------------------------------------*/
 /* Algorithm
	 Set a variable "isInsideBlank" to True
	 while there is a new char
		 if char is blank  
			if isInsideBlank == False
				print a blank
			set isInsideBlank to True
		 else
			 set isInsideBlank to False
			 print the char
 */

#include <stdio.h>

#define TRUE 1
#define FALSE 0

int main() {
	int ch;
	int isInsideSpace = FALSE;

	while ((ch = getchar()) != EOF) {
		if (ch == ' ') {
			if (isInsideSpace == FALSE)
				putchar(ch);
			isInsideSpace = TRUE;
		}
		else {
			isInsideSpace = FALSE;
			putchar(ch);
		}
	}

	return 0;
}

/*-------------------------------------------------------------------------*/
