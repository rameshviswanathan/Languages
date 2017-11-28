/*------------------------------------------------------------------------
 *
 * P64_ITOA.c: Write a program that prints a number to a character
 * string.
 *
 * COMPILE:
 *   To compile on VC++:
 *         cl.exe /EHsc /W4 P64_ITOA.c
 *            EHsc -->standard exception handling
 *            W4 is for enabling warning
 *   To compile on gcc:
 *            gcc -Wall -g -o P64_ITOA P64_ITOA.c
 *            Wall for enable all Warning
 *            g for debug information
 *
 * EXECUTE:
 *   On Windows, in the command prompt window, type
 *      P64_ITOA.exe
 *   On Unix, in the shell terminal window, type
 *      ./P64_ITOA
 *
 *-------------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>
#define ARR_LEN			20

void reverse(char *s) {
	char *e = s + strlen(s) - 1;
	while (s < e) {
		char temp = *s;
		*s = *e;
		*e = temp;
		s++; --e;
	}
}

/*-------------------------------------------------------------------------*/

void ITOA_1(char *s, int num) {
	int i = 0;

	// handle sign
	int sign = 1;
	if (num < 0) {
		sign = num;
		num = -num;
	}

	do {
		int cur_digit = num % 10;
		s[i++] = cur_digit + '0';
	} while (num = num / 10);

	if (sign < 0)
		s[i++] = '-';

	s[i] = '\0';

	reverse(s);
}

/*-------------------------------------------------------------------------*/

int main() {
	char s[ARR_LEN];
	int num = -12345;
	ITOA_1(s, num);
	printf("num: %s\n", s);

	return 0;
}

/*-------------------------------------------------------------------------*/
