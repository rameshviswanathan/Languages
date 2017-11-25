/*------------------------------------------------------------------------
 *
 * P49_Ex_2_8_RotateBits.c: Exercise 2-8. Write a function
 * rightrot(x,n) that returns the value of the integer x rotated to the
 * right by n positions.
 *
 * COMPILE:
 *   To compile on VC++:
 *         cl.exe /EHsc /W4 P49_Ex_2_8_RotateBits.c
 *            EHsc -->standard exception handling
 *            W4 is for enabling warning
 *   To compile on gcc:
 *            gcc -Wall -g -o P49_Ex_2_8_RotateBits P49_Ex_2_8_RotateBits.c
 *            Wall for enable all Warning
 *            g for debug information
 *
 * EXECUTE:
 *   On Windows, in the command prompt window, type
 *      P49_Ex_2_8_RotateBits.exe
 *   On Unix, in the shell terminal window, type
 *      ./P49_Ex_2_8_RotateBits
 *
 *-------------------------------------------------------------------------*/
#include <stdio.h>
unsigned char RotateBitsRight(unsigned char x, int n) {
	unsigned char rightBits;
	unsigned int maxCharInX;
	// assume n = 3

	unsigned char mask = ~(unsigned char)0;		//	1	1	1	1	_	1	1	1	1
	mask = mask << n;							//	1	1	1	1	_	1	0	0	0

	rightBits = x & ~mask;						//	0	0	0	0	_	0	x2	x1	x0

	maxCharInX = sizeof(x) << 3;

	rightBits = rightBits << (maxCharInX - n);	//	x2	x1	x0	0	_	0	0	0	0

	return rightBits | (x >> n);
}

/*-------------------------------------------------------------------------*/
int main(void) {
	unsigned char x = 0xa8;		//	1	0	1	1	_	1	0	0	0
	int n = 3;

	printf("x: 0x%x\n", x);
	printf("After rotating %d bits, 0x%x\n", n, RotateBitsRight(x, n));
	return 0;
}

/*-------------------------------------------------------------------------*/
