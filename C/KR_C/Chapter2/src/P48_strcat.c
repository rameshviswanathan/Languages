/*------------------------------------------------------------------------
 *
 * P48_strcat.c: Concatenate source string to the end of destination
 * string
 *
 * COMPILE:
 *   To compile on VC++:
 *         cl.exe /EHsc /W4 P48_strcat.c
 *            EHsc -->standard exception handling
 *            W4 is for enabling warning
 *   To compile on gcc:
 *            gcc -Wall -g -o P48_strcat P48_strcat.c
 *            Wall for enable all Warning
 *            g for debug information
 *
 * EXECUTE:
 *   On Windows, in the command prompt window, type
 *      P48_strcat.exe
 *   On Unix, in the shell terminal window, type
 *      ./P48_strcat
 *
 *-------------------------------------------------------------------------*/
#include <stdio.h>
#include <assert.h>

void strcat_ver1(char *s, char *d) {
	assert(s != NULL);
	assert(d != NULL);

	while (*s != '\0')
		s++;

	while ((*s++ = *d++) != '\0')
		;
}

/*-------------------------------------------------------------------------*/

int main(void) {
	char s[30] = "hello ";
	char d[30] = "world";

	printf("before concatination: %s\n", s);
	strcat_ver1(s, d);
	printf("after concatenation: %s\n", s);
	return 0;
}

/*-------------------------------------------------------------------------*/
