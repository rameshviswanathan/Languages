/*------------------------------------------------------------------------
 *
 * P24_Ex_1_13_Histogram.c: Write a program to print a histogram of
 * the lengths of words in its input.  It is easy to draw the histogram
 * with the bars horizontal; a vertical orientation is more challenging
 *
 * COMPILE:
 *   To compile on VC++:
 *         cl.exe /EHsc /W4 P24_Ex_1_13_Histogram.c
 *            EHsc -->standard exception handling 
 *            W4 is for enabling warning
 *   To compile on gcc:
 *            gcc -Wall -g -o P24_Ex_1_13_Histogram P24_Ex_1_13_Histogram.c
 *            Wall for enable all Warning
 *            g for debug information
 *
 * EXECUTE:
 *   On Windows, in the command prompt window, type
 *      P24_Ex_1_13_Histogram.exe
 *   On Unix, in the shell terminal window, type 
 *      ./P24_Ex_1_13_Histogram
 *
 *-------------------------------------------------------------------------*/
 /*Algorithm
 getWords:
 Input: A character array that can store words in input stream
 Define a variable "isInsideWord" to be FALSE
 while there is a character in input stream and it is not EOF:
 if new char is space
 if isInsideWord is TRUE:
 add null character to current char array
 increment char array to point to next element
 set isInsideWord to FALSE
 else
 add the element to the char array

 if isInsideWord is true
 add null character to current char array
 */

#include <stdio.h>
#include <ctype.h>

#define TRUE	1
#define FALSE	0

#define MAX_WORDS 10
#define MAX_WORD_SIZE 15

static int getWords(char wordArray[][MAX_WORD_SIZE], int *maxLength) {
	int i, j;
	int ch;
	int isInsideWord = FALSE;
	*maxLength = 0;

	i = j = 0;
	while ((ch = getchar()) != EOF) {
		if (isspace(ch)) {
			if (isInsideWord == TRUE) {
				wordArray[i][j] = '\0';
				if (*maxLength < j)
					*maxLength = j;
				j = 0;
				if (i <= MAX_WORDS - 1)
					++i;
			}

			isInsideWord = FALSE;
		}
		else {
			isInsideWord = TRUE;
			if (j < MAX_WORDS - 1)
				wordArray[i][j++] = ch;
		}
	}

	if (isInsideWord == TRUE) {
		wordArray[i][j] = '\0';
	}

	return i;
}

/*-------------------------------------------------------------------------*/

static int strlength(char *s) {
	int len = 0;
	while (*s) {
		++len;
		s++;
	}
	return len;
}

/*-------------------------------------------------------------------------*/

static void hHistogram(char words[][MAX_WORD_SIZE], int maxLength, int maxWords) {
	for (int i = 0; i < maxWords; ++i) {
		printf("%15s", words[i]);
		printf("|");
		int k = strlength(words[i]);
		while (k) {
			printf("*");
			--k;
		}
		printf("\n");
	}
}

/*-------------------------------------------------------------------------*/

static void vHistogram(char words[][MAX_WORD_SIZE], int maxLength, int maxWords) {
	for (int k = 0; k < maxLength; ++k) {
		for (int i = 0; i < maxWords; ++i) {
			int j = strlength(words[i]);
			if (maxLength - k <= j)
				printf("*");
			else
				printf(" ");
			printf("   ");
		}
		printf("\n");
	}
	printf("-----------------------------------------\n");
	for (int k = 0; k < maxLength; ++k) {
		for (int i = 0; i < maxWords; ++i) {
			int j = strlength(words[i]);
			if (k < j)
				printf("%c", words[i][k]);
			else
				printf(" ");
			printf("   ");
		}
		printf("\n");
	}

}

/*-------------------------------------------------------------------------*/

int main() {
	char wordArray[MAX_WORDS][MAX_WORD_SIZE];
	int maxLength = 0;
	int maxWords = getWords(wordArray, &maxLength);

	hHistogram(wordArray, maxLength, maxWords);
	vHistogram(wordArray, maxLength, maxWords);

	return 0;
}

/*-------------------------------------------------------------------------*/
