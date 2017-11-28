/*------------------------------------------------------------------------
 *
 * P65_Trim.c: Write a program that trims trailing white spaces.
 *
 * COMPILE:
 *   To compile on VC++:
 *         cl.exe /EHsc /W4 P65_Trim.c
 *            EHsc -->standard exception handling
 *            W4 is for enabling warning
 *   To compile on gcc:
 *            gcc -Wall -g -o P65_Trim P65_Trim.c
 *            Wall for enable all Warning
 *            g for debug information
 *
 * EXECUTE:
 *   On Windows, in the command prompt window, type
 *      P65_Trim.exe
 *   On Unix, in the shell terminal window, type
 *      ./P65_Trim
 *
 *-------------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int trim(char *s) {
	int i = strlen(s) - 1;

	for (; i >= 0 && isspace(s[i]); --i)
		;
	s[++i] = '\0';

	return i;
}

/*-------------------------------------------------------------------------*/
int main() {

	char *s = NULL;
	int cnt = 0;

	s = "abc           ";
	printf("before trimming : %s\n", s);
	cnt = trim(s);
	printf("after trimming: %s and len: %d\n", s, cnt);

	s = "abc			         \n";
	printf("before trimming : %s\n", s);
	cnt = trim(s);
	printf("after trimming: %s and len: %d\n", s, cnt);

	s = "";
	printf("before trimming : %s\n", s);
	cnt = trim(s);
	printf("after trimming: %s and len: %d\n", s, cnt);

	return 0;

}
/*-------------------------------------------------------------------------*/
