#include <stdio.h>
/*
 *print the alphabet using only putchar
 */

/**
 *main - entry point
 *spits out the lower case alphabet, use putchar no more
 *than twice
 *Return: 0
 */
int main(void)
{
	int c = 97;

	while (c <= 122)
	{
		putchar(c);
		c++;
	}
	putchar('\n');

	return (0);
}
