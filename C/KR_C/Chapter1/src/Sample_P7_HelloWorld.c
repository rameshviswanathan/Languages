/*------------------------------------------------------------------------
*
* Sample_P7_HelloWorld.c: The first C program that prints the greeting
* hello, world
* on the screen
*
* COMPILE:
*   To compile on VC++ cl.exe /EHsc /W4 Sample_P7_HelloWorld.c
*   EHsc -->standard exception handling and W4 is for enabling warning
*   To compile on gcc, gcc -Wall -o Sample_P7_HelloWorld Sample_P7_HelloWorld.c
*   Wall for enable all Warning
*
* EXECUTE
*   On Windows, type Sample_P7_HelloWorld.c in the command prompt window
*   On Unix type ./Sample_P7_HelloWorld in the shell terminal window
*
*-------------------------------------------------------------------------*/

#include <stdio.h>                  // include information about standard libray

int                                 // function return type
main()                              // function name with empty parenthesis
{                                   // opening brace
    printf("hello, world\n");       // printf is a library function
                                    // print the message hello, world to standard output
                                    // \n causes cursor to move to beginning of next line
                                    // character sequence enclosed in double qutoes is
                                    // called string constant

    return 0;                       // returns 0 to caller (here OS)

}                                   // closing brace

/*-------------------------------------------------------------------------*/