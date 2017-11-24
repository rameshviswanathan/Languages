/*------------------------------------------------------------------------
 *
 * P46_RandGen.c: Simple implementation of random generator
 *
 * COMPILE:
 *   To compile on VC++:
 *         cl.exe /EHsc /W4 P46_RandGen.c
 *            EHsc -->standard exception handling
 *            W4 is for enabling warning
 *   To compile on gcc:
 *            gcc -Wall -g -o P46_RandGen P46_RandGen.c
 *            Wall for enable all Warning
 *            g for debug information
 *
 * EXECUTE:
 *   On Windows, in the command prompt window, type
 *      P46_RandGen.exe
 *   On Unix, in the shell terminal window, type
 *      ./P46_RandGen
 *
 *-------------------------------------------------------------------------*/
#include <stdio.h>

unsigned long int next = 1;

int rand(void) {
	next = next * 1103515245 + 12345;

	return (unsigned int)(next / 65536) % 32768;
}

/*-------------------------------------------------------------------------*/

int srand(unsigned int seed) {
	next = seed;
}

/*-------------------------------------------------------------------------*/

int main(void) {
	for (int i = 1; i < 10; ++i)
		printf("random number: %d\n", srand(i * 34));

	return 0;
}

/*-------------------------------------------------------------------------*/
