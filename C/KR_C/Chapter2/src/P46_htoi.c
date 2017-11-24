/*------------------------------------------------------------------------
 *
 * P46_htoi.c: Convert hex number in string form into its equivalent
 * integer representation
 *
 * COMPILE:
 *   To compile on VC++:
 *         cl.exe /EHsc /W4 P46_htoi.c
 *            EHsc -->standard exception handling
 *            W4 is for enabling warning
 *   To compile on gcc:
 *            gcc -Wall -g -o P46_htoi P46_htoi.c
 *            Wall for enable all Warning
 *            g for debug information
 *
 * EXECUTE:
 *   On Windows, in the command prompt window, type
 *      P46_htoi.exe
 *   On Unix, in the shell terminal window, type
 *      ./P46_htoi
 *
 *-------------------------------------------------------------------------*/
#include <stdio.h>
#include <assert.h>

int htoi_ver1(char *s) {
	assert(s != NULL);
	int val = 0;

	//strip spaces
	while (*s == ' ' || *s == '\t')
		s++;

	//ignore 0x or 0X prefix
	if (*s == '0') {
		s++;
		if (*s == 'X' || *s == 'x')
			s++;
	}

	while (*s != NULL) {
		int cur_digit = 0;
		if (*s >= '0' && *s <= '9')
			cur_digit = *s - '0';
		else if (*s >= 'a' && *s <= 'f')
			cur_digit = *s - 'a';
		else if (*s >= 'A' && *s <= 'F')
			cur_digit = *s - 'A';
		else
			break;

		val = val * 16 + cur_digit;
		s++;
	}
	return val;
}

/*-------------------------------------------------------------------------*/
int main() {
	char *s = "0x1234";
	printf("atoi(%s) is 0x%x\n", s, htoi_ver1(s));

	s = "0X1234";
	printf("atoi(%s) is 0x%x\n", s, htoi_ver1(s));

	s = "             0x1234";
	printf("atoi(%s) is 0x%x\n", s, htoi_ver1(s));

	s = "		 0X1234";
	printf("atoi(%s) is 0x%X\n", s, htoi_ver1(s));

	return 0;
}

/*-------------------------------------------------------------------------*/