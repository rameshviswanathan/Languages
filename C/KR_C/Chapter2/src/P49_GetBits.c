/*------------------------------------------------------------------------
 *
 * P49_GetBits.c: Getbits(x, n1, n2) returns n2 bits from n1th bit of
 * x and it is right adjusted.  For example GetBits(x, 4, 3), will return
 * right-adjusted x4, x3, x2 bits of x.
 *
 * COMPILE:
 *   To compile on VC++:
 *         cl.exe /EHsc /W4 P49_GetBits.c
 *            EHsc -->standard exception handling
 *            W4 is for enabling warning
 *   To compile on gcc:
 *            gcc -Wall -g -o P49_GetBits P49_GetBits.c
 *            Wall for enable all Warning
 *            g for debug information
 *
 * EXECUTE:
 *   On Windows, in the command prompt window, type
 *      P49_GetBits.exe
 *   On Unix, in the shell terminal window, type
 *      ./P49_GetBits
 *
 *-------------------------------------------------------------------------*/
#include <stdio.h>

int GetBits(unsigned char x, int p, int n) {
	unsigned char mask = (unsigned char)~0;		//1111_1111
	mask = mask << n;							//1111_1000
	mask = ~mask;								//0000_0111

	// right shifting so that the required bits are right aligned
	x = x >> (p - n + 1);

	return x & mask;
}

/*-------------------------------------------------------------------------*/

int main(void) {
	unsigned char x = 0x5a;
	unsigned int p = 4;
	unsigned int n = 3;

	printf("original value: 0x%x\n", x);
	printf("%d bits from position %d is : 0x%x\n", n, p, GetBits(x, p, n));
	return 0;
}

/*-------------------------------------------------------------------------*/
