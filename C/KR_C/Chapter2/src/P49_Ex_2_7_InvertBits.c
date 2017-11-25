/*------------------------------------------------------------------------
 *
 * P49_Ex_2_7_InvertBits.c: Exercise 2-7. Write a function
 * invert(x,p,n) that returns x with the n bits that begin at position p
 * inverted (i.e., 1 changed into 0 and vice versa), leaving the others
 * unchanged.
 *
 * COMPILE:
 *   To compile on VC++:
 *         cl.exe /EHsc /W4 P49_Ex_2_7_InvertBits.c
 *            EHsc -->standard exception handling
 *            W4 is for enabling warning
 *   To compile on gcc:
 *            gcc -Wall -g -o P49_Ex_2_7_InvertBits P49_Ex_2_7_InvertBits.c
 *            Wall for enable all Warning
 *            g for debug information
 *
 * EXECUTE:
 *   On Windows, in the command prompt window, type
 *      P49_Ex_2_7_InvertBits.exe
 *   On Unix, in the shell terminal window, type
 *      ./P49_Ex_2_7_InvertBits
 *
 *-------------------------------------------------------------------------*/

#include <stdio.h>

unsigned char InvertBits(unsigned char x, int p, int n) {
	unsigned char inverted;
	// assume n = 3 p = 4
	unsigned char mask = ~(unsigned char)0;		//	1	1	1	1	_	1	1	1	1
	mask = mask << (n);							//	1	1	1	1	_	1	0	0	0
	mask = ~mask;								//	0	0	0	0	_	0	1	1	1
	mask = mask << (p - n + 1);					//	0	0	0	1	_	1	1	0	0

	inverted = ~(x & mask); 					//	1	1	1	X4	_	X3	X2	1	1

	return (x & ~mask) | (inverted);

}

/*-------------------------------------------------------------------------*/

int main(void) {
	unsigned char x = 0xff;
	int p = 4;
	int n = 3;
	printf("x: 0x%x  p: %d  n: %d\n", x, p, n);
	printf("After inverting: \n");
	printf("x: 0x%x\n", InvertBits(x, p, n));

	return 0;
}

/*-------------------------------------------------------------------------*/
