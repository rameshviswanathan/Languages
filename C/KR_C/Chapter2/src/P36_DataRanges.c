/*------------------------------------------------------------------------
 *
 * P36_DataRanges.c: Write a program to determine the ranges of char,
 * short, int, and long variables, both signed and unsigned, by printing
 * appropriate values from standard headers and by direct computation.
 * Harder if you compute them: determine the ranges of the various
 * floating-point types
 *
 * COMPILE:
 *   To compile on VC++:
 *         cl.exe /EHsc /W4 P36_DataRanges.c
 *            EHsc -->standard exception handling
 *            W4 is for enabling warning
 *   To compile on gcc:
 *            gcc -Wall -g -o P36_DataRanges P36_DataRanges.c
 *            Wall for enable all Warning
 *            g for debug information
 *
 * EXECUTE:
 *   On Windows, in the command prompt window, type
 *      P36_DataRanges.exe
 *   On Unix, in the shell terminal window, type
 *      ./P36_DataRanges
 *
 *-------------------------------------------------------------------------*/

#include <stdio.h>
#include <limits.h>
#include <float.h>

void compute_char_properties(void) {
	unsigned char uch;
	signed char sch;
	int cnt = 0;

	// figuring out unsigned char properties
	uch = 1;
	while (uch > 0) {
		++cnt;
		uch = uch << 1;
	}
	uch = (unsigned char)~(0);

	printf("The data range of unsigned char: %d to %d\n", 0, uch);
	printf("The number of bits of unsigned char: %d\n", cnt);

	sch = 1;
	cnt = 0;
	while (sch > 0) {
		++cnt;
		sch = sch << 1;
	}
	cnt++; // to account for sign bit

	printf("\nThe data range of signed char: %d to %d\n", sch, ~sch);
	printf("The number of bits of signed char: %d\n", cnt);
	printf("-------------------------------------------\n");
}

/*-------------------------------------------------------------------------*/

void compute_short_properties(void) {
	unsigned short u_short;
	signed short s_short;
	int cnt = 0;

	// figuring out unsigned char properties
	u_short = 1;
	while (u_short > 0) {
		++cnt;
		u_short = u_short << 1;
	}
	u_short = (unsigned char)~(0);

	printf("The data range of unsigned char: %d to %d\n", 0, u_short);
	printf("The number of bits of unsigned char: %d\n", cnt);

	s_short = 1;
	cnt = 0;
	while (s_short > 0) {
		++cnt;
		s_short = s_short << 1;
	}
	cnt++; // to account for sign bit

	printf("\nThe data range of signed char: %d to %d\n", s_short, ~s_short);
	printf("The number of bits of signed char: %d\n", cnt);
	printf("-------------------------------------------\n");
}

/*-------------------------------------------------------------------------*/

void compute_long_properties(void)
{
	unsigned long u_long;
	signed long s_long;
	int cnt = 0;

	// figuring out unsigned char properties
	u_long = (unsigned long)1;
	while (u_long > 0) {
		++cnt;
		u_long = u_long << 1;
	}
	u_long = (unsigned long)~(0);

	printf("The data range of unsigned long: %lu to %lu\n", 0, u_long);
	printf("The number of bits of unsigned long: %d\n", cnt);

	s_long = 1;
	cnt = 0;
	while (s_long > 0) {
		++cnt;
		s_long = s_long << 1;
	}
	cnt++; // to account for sign bit

	printf("\nThe data range of signed long: %ld to %ld\n", s_long, ~s_long);
	printf("The number of bits of signed long: %d\n", cnt);
	printf("-------------------------------------------\n");
}

/*-------------------------------------------------------------------------*/

void compute_int_properties(void)
{
	unsigned int u_int;
	signed int s_int;
	int cnt = 0;

	// figuring out unsigned char properties
	u_int = 1;
	while (u_int > 0) {
		++cnt;
		u_int = u_int << 1;
	}
	u_int = (unsigned int)~(0);

	printf("The data range of unsigned int: %u to %u\n", 0, u_int);
	printf("The number of bits of unsigned int: %d\n", cnt);

	s_int = (int)1;
	cnt = 0;
	while (s_int > 0) {
		++cnt;
		s_int = s_int << 1;
	}
	cnt++; // to account for sign bit

	printf("\nThe data range of signed int: %d to %d\n", s_int, ~s_int);
	printf("The number of bits of signed int: %d\n", cnt);
	printf("-------------------------------------------\n");
}

/*-------------------------------------------------------------------------*/

void compute_l_long_properties(void) {
	unsigned long long u_l_long;
	signed long long s_l_long;
	int cnt = 0;

	// figuring out unsigned char properties
	u_l_long = 1;
	while (u_l_long > 0) {
		++cnt;
		u_l_long = u_l_long << 1;
	}
	u_l_long = (unsigned long long)~(0);

	printf("The data range of unsigned long long: %llu to %llu\n", (unsigned long long)0, u_l_long);
	printf("The number of bits of unsigned long long: %d\n", cnt);

	s_l_long = (signed long long)1;
	cnt = 0;
	while (s_l_long > 0) {
		++cnt;
		s_l_long = s_l_long << 1;
	}
	cnt++; // to account for sign bit

	printf("\nThe data range of signed long long: %lld to %lld\n", s_l_long, ~s_l_long);
	printf("The number of bits of signed long long: %d\n", cnt);
	printf("-------------------------------------------\n");
}

/*-------------------------------------------------------------------------*/

void print_from_header() {
	printf("\nThe data range of signed char: %d to %d\n", SCHAR_MIN, SCHAR_MAX);
	printf("The data range of unsigned char: %u to %u\n", 0, UCHAR_MAX);

	printf("\nThe data range of signed short: %d to %d\n", SHRT_MIN, SHRT_MAX);
	printf("The data range of unsigned short: %u to %u\n", 0, USHRT_MAX);

	printf("\nThe data range of signed int: %d to %d\n", INT_MIN, INT_MAX);
	printf("The data range of unsigned int: %u to %u\n", 0, UINT_MAX);

	printf("\nThe data range of signed long: %ld to %ld\n", LONG_MIN, LONG_MAX);
	printf("The data range of unsigned long: %lu to %lu\n", 0, ULONG_MAX);

	//printf("\nThe data range of signed long long: %lld to %lld\n", LONG_LONG_MIN, LONG_LONG_MAX);
	//printf("The data range of unsigned long long: %llu to %llu\n", 0, ULONG_LONG_MAX);

	printf("-------------------------------------------\n");

}

/*-------------------------------------------------------------------------*/

void compute_ranges(void) {
	printf("\nThe data range of signed char: %d to %d\n", -(char)((unsigned char)~0 >> 1), (char)((unsigned char)~0 >> 1));
	printf("The data range of unsigned char: %u to %u\n", 0, (unsigned char)~0);

	printf("\nThe data range of signed short: %d to %d\n", -(short)((unsigned short)~0 >> 1), (short)((unsigned short)~0 >> 1));
	printf("The data range of unsigned short: %u to %u\n", 0, (unsigned short)~0);

	printf("\nThe data range of signed int: %d to %d\n", -(int)((unsigned int)~0 >> 1), (int)((unsigned int)~0 >> 1));
	printf("The data range of unsigned int: %u to %u\n", 0, (unsigned int)~0);

	printf("\nThe data range of signed long: %ld to %ld\n", -(long)((unsigned long)~0 >> 1), (long)((unsigned long)~0 >> 1));
	printf("The data range of unsigned long: %lu to %lu\n", 0, (unsigned long)~0);

	printf("\nThe data range of signed long long: %lld to %lld\n", -(long long)((unsigned long long)~0 >> 1), (long long)((unsigned long long)~0 >> 1));
	printf("The data range of unsigned long long: %llu to %llu\n", (unsigned long long)0, (unsigned long long)~0);

	printf("-------------------------------------------\n");
}

/*-------------------------------------------------------------------------*/

int main()
{
	// compute option 1
	compute_char_properties();
	compute_short_properties();
	compute_int_properties();
	compute_long_properties();
	compute_l_long_properties();

	// print from header
	print_from_header();

	// compute option 2
	compute_ranges();
	return 0;
}

/*-------------------------------------------------------------------------*/
