/*------------------------------------------------------------------------
 *
 * P39_StringLength.c: Compute the length of the string
 *
 * COMPILE:
 *   To compile on VC++:
 *         cl.exe /EHsc /W4 P39_StringLength.c
 *            EHsc -->standard exception handling 
 *            W4 is for enabling warning
 *   To compile on gcc:
 *            gcc -Wall -g -o P39_StringLength P39_StringLength.c
 *            Wall for enable all Warning
 *            g for debug information
 *
 * EXECUTE:
 *   On Windows, in the command prompt window, type
 *      P39_StringLength.exe
 *   On Unix, in the shell terminal window, type 
 *      ./P39_StringLength
 *
 *-------------------------------------------------------------------------*/

#include <stdio.h>
#include <assert.h>

size_t get_string_length_3(char *str) {
	assert(str != NULL);
	size_t i = 0;
	for (i = 0; str[i] != '\0'; ++i)
		;
	return i;
}

size_t get_string_length_2(char *str) {
	assert(str != NULL);
	size_t cnt = 0;
	while (*str++) {
		cnt++;
	}
	return cnt;
}

size_t get_string_length(char *str) {
	assert(str != NULL);
	char *p = str;
	while (*p) {
		p++;
	}
	return p - str;
}

int main(void) {
	//compute string length
	char *s = "abcdef";
	printf("Length of %s: %u\n", s, get_string_length(s));
	printf("Length of %s: %u\n", s, get_string_length_2(s));
	printf("Length of %s: %u\n", s, get_string_length_3(s));
	return 0;
}
/*-------------------------------------------------------------------------*/
