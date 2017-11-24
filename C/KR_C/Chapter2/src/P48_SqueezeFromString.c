/*------------------------------------------------------------------------
 *
 * P48_SqueezeFromString.c: Write an alternative version of
 * squeeze(s1,s2) that deletes each character in s1 that matches any
 * character in the string s2.
 *
 * COMPILE:
 *   To compile on VC++:
 *         cl.exe /EHsc /W4 P48_SqueezeFromString.c
 *            EHsc -->standard exception handling
 *            W4 is for enabling warning
 *   To compile on gcc:
 *            gcc -Wall -g -o P48_SqueezeFromString P48_SqueezeFromString.c
 *            Wall for enable all Warning
 *            g for debug information
 *
 * EXECUTE:
 *   On Windows, in the command prompt window, type
 *      P48_SqueezeFromString.exe
 *   On Unix, in the shell terminal window, type
 *      ./P48_SqueezeFromString
 *
 *-------------------------------------------------------------------------*/
#include <stdio.h>
#include <assert.h>

int findCharInWord(char *ref_word, char c) {
	int found = 0;

	while (*ref_word != '\0' && !found) {
		if (*ref_word == c)
			found = 1;
		ref_word++;
	}

	return found;
}

/*-------------------------------------------------------------------------*/

void squeeze(char *src_word, char *ref_word) {
	int i, j;
	assert(src_word != NULL);
	assert(ref_word != NULL);

	for (i = 0, j = 0; src_word[i] != '\0'; ++i) {
		int found = findCharInWord(ref_word, src_word[i]);
		if (!found)
			src_word[j++] = src_word[i];
	}
}

/*-------------------------------------------------------------------------*/

int main(void) {
	char src[30] = "hello world";
	char ref[10] = "aeiou";

	printf("before squeeze: %s\n", src);
	squeeze(src, ref);
	printf("after squeeze: %s\n", src);

	return 0;
}

/*-------------------------------------------------------------------------*/
