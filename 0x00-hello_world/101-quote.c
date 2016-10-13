#include <stdio.h>
#include <unistd.h>
/*
 *prints to the standard error without using common functions.
 */

/**
 *main - entry point
 *writes a string to the standard error
 *Return: 1
 */
int main(void)
{
	write(2, "and that piece of art is useful - Dora Korpar, 2015-10-19\n"
	      , 59);
	return (1);
}
