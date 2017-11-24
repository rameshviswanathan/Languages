/*------------------------------------------------------------------------
 *
 * P47_Squeeze.c: Delete all occurrence of a character from a string
 *
 * COMPILE:
 *   To compile on VC++:
 *         cl.exe /EHsc /W4 P47_Squeeze.c
 *            EHsc -->standard exception handling
 *            W4 is for enabling warning
 *   To compile on gcc:
 *            gcc -Wall -g -o P47_Squeeze P47_Squeeze.c
 *            Wall for enable all Warning
 *            g for debug information
 *
 * EXECUTE:
 *   On Windows, in the command prompt window, type
 *      P47_Squeeze.exe
 *   On Unix, in the shell terminal window, type
 *      ./P47_Squeeze
 *
 *-------------------------------------------------------------------------*/

#include <stdio.h>

void squeeze(char s[], char c) {
	int i, j;

	for (i = 0, j = 0; s[i] != '\0'; ++i) {
		if (s[i] != c)
			s[j++] = s[i];
	}
	s[j] = '\0';
}

/*-------------------------------------------------------------------------*/

int main(void) {
	char s[20] = "hello World";
	char c = 'l';

	printf("Before squeeze: %s\n", s);
	squeeze(s, c);
	printf(" After squeeze: %s\n", s);

	return 0;
}

/*-------------------------------------------------------------------------*/
