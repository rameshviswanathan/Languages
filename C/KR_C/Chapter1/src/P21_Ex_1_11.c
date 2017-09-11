/*------------------------------------------------------------------------
 *
 * P21_Ex_1_11.c: How would you test word count program?
 *
 * COMPILE:
 *   To compile on VC++:
 *         cl.exe /EHsc /W4 P21_Ex_1_11.c
 *            EHsc -->standard exception handling
 *            W4 is for enabling warning
 *   To compile on gcc:
 *            gcc -Wall -g -o P21_Ex_1_11 P21_Ex_1_11.c
 *            Wall for enable all Warning
 *            g for debug information
 *
 * EXECUTE:
 *   On Windows, in the command prompt window, type
 *      P21_Ex_1_11.exe
 *   On Unix, in the shell terminal window, type
 *      ./P21_Ex_1_11
 *
 *-------------------------------------------------------------------------*/

#include <stdio.h>
#include <assert.h>
#define TRUE	1
#define FALSE	0

 /* algorithm
	 define a variable "isInsideBlank" and set to TRUE
	 define a counter variable "cnt" and set it to 0
	 while there is a next char(ch) and not equal to EOF
		 if ch is blank
			 set isInsideBlank to TRUE
		 else
			 if isInsideBlank is TRUE
				 set isInsideBlank to FALSE
				 increment the counter

		 return cnt
 */

int wordCount(char *s)
{
	int isInsideBlank = TRUE;
	int cnt = 0;

	assert(s !=  NULL);

	while (*s) {
		if (isspace(*s))
			isInsideBlank = TRUE;
		else {
			if (isInsideBlank) {
				isInsideBlank = FALSE;
				++cnt;
			}
		}
		s++;
	}

	return cnt;
}


int main() {
	printf("word count: %d\n", wordCount("life is good"));
	return 0;
}

/*-------------------------------------------------------------------------*/
