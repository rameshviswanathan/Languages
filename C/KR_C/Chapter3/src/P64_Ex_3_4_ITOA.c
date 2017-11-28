/*------------------------------------------------------------------------
 *
 * P64_Ex_3_4_ITOA.c: In a two's complement number representation, our
 * version of itoa does not handle the largest negative number, that is,
 * the value of n equal to -(2wordsize-1). Explain why not. Modify it to
 * print that value correctly, regardless of the machine on which it runs
 *
 * COMPILE:
 *   To compile on VC++:
 *         cl.exe /EHsc /W4 P64_Ex_3_4_ITOA.c
 *            EHsc -->standard exception handling
 *            W4 is for enabling warning
 *   To compile on gcc:
 *            gcc -Wall -g -o P64_Ex_3_4_ITOA P64_Ex_3_4_ITOA.c
 *            Wall for enable all Warning
 *            g for debug information
 *
 * EXECUTE:
 *   On Windows, in the command prompt window, type
 *      P64_Ex_3_4_ITOA.exe
 *   On Unix, in the shell terminal window, type
 *      ./P64_Ex_3_4_ITOA
 *
 *-------------------------------------------------------------------------*/
#include <stdio.h>

#define abs(x)  ((x) < 0 ? -(x) : (x))

enum { FALSE, TRUE };


void reverse(char *s) {
	char *e = s;
	while (*e != '\0')
		e++;
	e--;

	for (; s < e; s++, --e) {
		char temp = *s;
		*s = *e;
		*e = temp;
	}
}

/*-------------------------------------------------------------------------*/
void IntToAsciiVer2(char *s, char num) {
	int i = 0;
	int sign = num < 0 ? -1 : 1;

	do {
		int cur_digit = num % 10;
		s[i++] = abs(cur_digit) + '0';
	} while ((num /= 10) != 0);

	if (sign < 0)
		s[i++] = '-';

	s[i] = '\0';

	reverse(s);
}

/*-------------------------------------------------------------------------*/

void IntToAsciiVer1(char *s, char num) {
	int sign = 1;
	int isNegativeMax = FALSE;
	int i = 0;

	/* if negative, set sign and make it positive number */
	if (num < 0) {
		sign = -1;
		if ((char)(num << 1) == (char)0) {
			num = num + 1;
			isNegativeMax = TRUE;
		}

		num = -num;
	}

	do {
		if (isNegativeMax) {
			s[i++] = num % 10 + 1 + '0';
			isNegativeMax = FALSE;
		}
		else
			s[i++] = num % 10 + '0';
	} while ((num /= 10) > 0);

	if (sign == -1)
		s[i++] = '-';

	s[i] = '\0';

	reverse(s);
}

/*-------------------------------------------------------------------------*/

int main(void) {
	char s[30];

	IntToAsciiVer1(s, -128);
	printf("ver1: %s\n", s);

	IntToAsciiVer2(s, -128);
	printf("ver2: %s\n", s);

	return 0;
}

/*-------------------------------------------------------------------------*/
