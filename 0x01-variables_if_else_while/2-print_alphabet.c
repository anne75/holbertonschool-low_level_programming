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
	char c = 'a';

	while (c <= 'z')
	{
		putchar(c);
		c++;
	}
	putchar('\n');

	return (0);
}
