/*------------------------------------------------------------------------
 *
 * P43_lowerCase.c: Convert all characters in a string to lower case
 *
 * COMPILE:
 *   To compile on VC++:
 *         cl.exe /EHsc /W4 P43_lowerCase.c
 *            EHsc -->standard exception handling
 *            W4 is for enabling warning
 *   To compile on gcc:
 *            gcc -Wall -g -o P43_lowerCase P43_lowerCase.c
 *            Wall for enable all Warning
 *            g for debug information
 *
 * EXECUTE:
 *   On Windows, in the command prompt window, type
 *      P43_lowerCase.exe
 *   On Unix, in the shell terminal window, type
 *      ./P43_lowerCase
 *
 *-------------------------------------------------------------------------*/
#include <stdio.h>

int lower(int c) {
	if (c >= 'A' && c <= 'Z')
		return c - 'A' + 'a';

	return c;
}

/*-------------------------------------------------------------------------*/

int main(void) {
	char word[20] = "Hello WORLD";
	char *p = word;

	printf("word before conversion: %s\n", word);
	while (*p) {
		*p = lower(*p);
		p++;
	}

	printf("word after conversion: %s\n", word);

	return 0;
}
/*-------------------------------------------------------------------------*/
