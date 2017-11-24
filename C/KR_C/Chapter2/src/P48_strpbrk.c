/*------------------------------------------------------------------------
 *
 * P48_strpbrk.c: Write the function any(s1,s2), which returns the
 * first location in a string s1 where any character from the string s2
 * occurs, or -1 if s1 contains no characters from s2. (The standard
 * library function strpbrk does the same job but returns a pointer to
 * the location.)
 *
 * COMPILE:
 *   To compile on VC++:
 *         cl.exe /EHsc /W4 P48_strpbrk.c
 *            EHsc -->standard exception handling
 *            W4 is for enabling warning
 *   To compile on gcc:
 *            gcc -Wall -g -o P48_strpbrk P48_strpbrk.c
 *            Wall for enable all Warning
 *            g for debug information
 *
 * EXECUTE:
 *   On Windows, in the command prompt window, type
 *      P48_strpbrk.exe
 *   On Unix, in the shell terminal window, type
 *      ./P48_strpbrk
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

int any(char *src_word, char *ref_word) {
	int i;
	assert(src_word != NULL);
	assert(ref_word != NULL);

	for (i = 0; src_word[i] != '\0'; ++i) {
		int found = findCharInWord(ref_word, src_word[i]);
		if (found)
			break;
	}
	if (src_word[i] == '\0')
		i = -1;

	return i;
}

/*-------------------------------------------------------------------------*/

int main(void) {
	char src[30] = "hello world";
	char ref[10] = "";

	printf("reference string: %s\n", ref);
	printf("source string: %s\n", src);
	printf("first occurrence in %s is : %d \n", src, any(src, ref));

	return 0;
}

/*-------------------------------------------------------------------------*/
