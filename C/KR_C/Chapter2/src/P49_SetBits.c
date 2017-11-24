/*------------------------------------------------------------------------
 *
 * P49_SetBits.c: Write a function setbits(x,p,n,y) that returns x
 * with the n bits that begin at position p set to the rightmost n bits
 * of y, leaving the other bits unchanged.
 *
 * COMPILE:
 *   To compile on VC++:
 *         cl.exe /EHsc /W4 P49_SetBits.c
 *            EHsc -->standard exception handling
 *            W4 is for enabling warning
 *   To compile on gcc:
 *            gcc -Wall -g -o P49_SetBits P49_SetBits.c
 *            Wall for enable all Warning
 *            g for debug information
 *
 * EXECUTE:
 *   On Windows, in the command prompt window, type
 *      P49_SetBits.exe
 *   On Unix, in the shell terminal window, type
 *      ./P49_SetBits
 *
 *-------------------------------------------------------------------------*/
#include <stdio.h>

int SetBits(unsigned char x, int p, int n, unsigned char y) {
	// assume p = 4 and n = 3
	unsigned char mask = ~(unsigned char)0;		//	1	1	1	1	_	1	1	1	1
	mask = mask << n;							//  1	1	1	1	_	1	0	0	0
	int mask2 = ~mask << (p - n + 1);			//	0	0	0	1	_	1	1	0	0

	y = y & ~mask;
	printf("y1: 0x%x\n", y);
	y = y << (p - n + 1);						//	0	0	0	y2	_	y1	y0	0	0
	printf("y: 0x%x\n", y);

	x = x & ~mask2;								//	x7	x6	x5	0	_	0	0	x1	x0
	printf("x: 0x%x\n", x);

	return x | y;

}

/*-------------------------------------------------------------------------*/

void main(void) {
	unsigned char x = 0x3c;		//	0	0	1	1	_	1	1	0	0
	unsigned int p = 4;
	unsigned int n = 3;
	unsigned char y = 0x0a;		//	0	0	0	0	_	1	0	1	0

								//	0	0	1	0	_	1	0	0	0

	printf("x : 0x%x, y : 0x%x, n : %d p : %d\n", x, y, n, p);
	printf("Setting %d bits from rightmost y into %d th bits of x: 0x%x\n", n, p, SetBits(x, p, n, y));

	return 0;
}

/*-------------------------------------------------------------------------*/
