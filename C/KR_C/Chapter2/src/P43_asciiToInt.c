/*------------------------------------------------------------------------
 *
 * P43_asciiToInt.c: Convert digit in string form to integer
 *
 * COMPILE:
 *   To compile on VC++:
 *         cl.exe /EHsc /W4 P43_asciiToInt.c
 *            EHsc -->standard exception handling
 *            W4 is for enabling warning
 *   To compile on gcc:
 *            gcc -Wall -g -o P43_asciiToInt P43_asciiToInt.c
 *            Wall for enable all Warning
 *            g for debug information
 *
 * EXECUTE:
 *   On Windows, in the command prompt window, type
 *      P43_asciiToInt.exe
 *   On Unix, in the shell terminal window, type
 *      ./P43_asciiToInt
 *
 *-------------------------------------------------------------------------*/
#include <stdio.h>
#include <assert.h>

int atoi_ver2(char *str) {
	assert(str != NULL);

	int val = 0;
	int sign = 1;

	//strip off beginning space
	while (*str == ' ' || *str == '\t')
		str++;

	// check if it starts with sign symbol
	if (*str == '+' || *str == '-') {
		sign = *str == '-' ? -1 : 1;
		str++;
	}

	//get int value
	for (; *str != NULL && *str >= '0' && *str <= '9'; ++str)
	{
		int cur_digit = *str - '0';
		val = val * 10 + cur_digit;
	}

	return val * sign;
}

/*-------------------------------------------------------------------------*/

int atoi_ver1(char *str) {
	assert(str != NULL);

	int val = 0;
	for (int i = 0; str[i] != '\0' && str[i] >= '0' && str[i] <= '9'; ++i) {
		int cur_digit = str[i] - '0';
		val = val * 10 + cur_digit;
	}

	return val;
}

/*-------------------------------------------------------------------------*/

int main() {
	char *s = "1234";
	printf("atoi(%s) is %d\n", s, atoi_ver1(s));
	printf("atoi(%s) is %d\n", s, atoi_ver2(s));

	s = "-1234";
	printf("atoi(%s) is %d\n", s, atoi_ver2(s));

	s = "             -1234";
	printf("atoi(%s) is %d\n", s, atoi_ver2(s));

	s = "		 +1234";
	printf("atoi(%s) is %d\n", s, atoi_ver2(s));

	return 0;
}