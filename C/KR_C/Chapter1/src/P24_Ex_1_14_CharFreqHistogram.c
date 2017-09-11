/*------------------------------------------------------------------------
 *
 * P24_Ex_1_14_CharFreqHistogram.c: Write a program to print a
 * histogram of the frequencies of different characters in its input.
 *
 * COMPILE:
 *   To compile on VC++:
 *         cl.exe /EHsc /W4 P24_Ex_1_14_CharFreqHistogram.c
 *            EHsc -->standard exception handling 
 *            W4 is for enabling warning
 *   To compile on gcc:
 *            gcc -Wall -g -o P24_Ex_1_14_CharFreqHistogram P24_Ex_1_14_CharFreqHistogram.c
 *            Wall for enable all Warning
 *            g for debug information
 *
 * EXECUTE:
 *   On Windows, in the command prompt window, type
 *      P24_Ex_1_14_CharFreqHistogram.exe
 *   On Unix, in the shell terminal window, type 
 *      ./P24_Ex_1_14_CharFreqHistogram
 *
 *-------------------------------------------------------------------------*/
#include <stdio.h>

#define ALPHA_CHAR_CNT 26
#define NUM_CHAR_CNT 10

void printLetterHistogram(char *dataArray, int count, char startLetter) {
	for (int i = 0; i < count; ++i) {
		printf("%c | ", i + startLetter);
		for (int j = 0; j < dataArray[i]; ++j)
			printf("*");
		printf("\n");
	}
}

/*-------------------------------------------------------------------------*/

int main() {
	char lowerLetters[ALPHA_CHAR_CNT];
	char upperLetters[ALPHA_CHAR_CNT];
	char digits[NUM_CHAR_CNT];

	int ch;

	for (int i = 0; i < ALPHA_CHAR_CNT; ++i) {
		lowerLetters[i] = 0;
		upperLetters[i] = 0;
	}

	for (int i = 0; i < NUM_CHAR_CNT; ++i)
		digits[i] = 0;


	while ((ch = getchar()) != EOF) {
		if (ch >= 'a' && ch <= 'z')
			++lowerLetters[ch - 'a'];
		else if (ch >= 'A' && ch <= 'Z')
			++upperLetters[ch - 'A'];
		else if (ch >= '0' && ch <= '9')
			++digits[ch - '0'];
	}

	printf("\n\n------------------------------------------------------------------\n\n");
	printLetterHistogram(lowerLetters, ALPHA_CHAR_CNT, 'a');
	printf("\n\n------------------------------------------------------------------\n\n");
	printLetterHistogram(upperLetters, ALPHA_CHAR_CNT, 'A');
	printf("\n\n------------------------------------------------------------------\n\n");
	printLetterHistogram(digits, NUM_CHAR_CNT, '0');
	printf("\n\n------------------------------------------------------------------\n\n");

	return 0;
}

/*-------------------------------------------------------------------------*/
