/*------------------------------------------------------------------------
 *
 * P20_WordCount.c: Count words in input
 *
 * COMPILE:
 *   To compile on VC++:
 *         cl.exe /EHsc /W4 P20_WordCount.c
 *            EHsc -->standard exception handling 
 *            W4 is for enabling warning
 *   To compile on gcc:
 *            gcc -Wall -g -o P20_WordCount P20_WordCount.c
 *            Wall for enable all Warning
 *            g for debug information
 *
 * EXECUTE:
 *   On Windows, in the command prompt window, type
 *      P20_WordCount.exe
 *   On Unix, in the shell terminal window, type 
 *      ./P20_WordCount
 *
 *-------------------------------------------------------------------------*/
/* algorithm 
set a variable isInsideWord to track if we are inside the word
set isInsideWord to FALSE
Set a counter wrd_cnt to 0

while there is a new char and is not EOF
	if new char is space
		set isInsideWord to FALSE
	else if isInsideWord is set to FALSE
		set isInsideWord to TRUE
		increment count
*/

/*-------------------------------------------------------------------------*/

#include <stdio.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0

int WordCount() {
	int ch;
	int cnt = 0;
	int isInsideWord = FALSE;

	while ((ch = getchar()) != EOF) {
		if (isspace(ch))
			isInsideWord = FALSE;
		else if (isInsideWord == FALSE) {
			isInsideWord = TRUE;
			++cnt;
		}
	}
	return cnt;
}

int main() {

	printf("word count in input: %d\n", WordCount());
	return 0;
}