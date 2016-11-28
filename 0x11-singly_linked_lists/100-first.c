#include <stdio.h>

/**
 * premain - function to execute before main
 *
 */
void __attribute__ ((constructor)) premain()
{
	printf("You're beat! and yet, you must allow,\nI bore my house upon my back!\n");
}

/*
 *http://stackoverflow.com/questions/8713470/executing-code-before-main
 *separate prototype from function
 *https://www.hackerearth.com/practice/notes/c-program-callling-a-function
 *-before-main/
 */
