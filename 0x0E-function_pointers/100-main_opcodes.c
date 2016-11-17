#include <stdlib.h>
#include <stdio.h>

/**
 * main - not really useful
 * @ac: number of arguments
 * @av: will i use it ?
 * Return: 0
 */
int main(int ac, char **av)
{
	int i, b;
	unsigned char *opcodes;
/*use chars as each opcode is two char long*/

	if (ac != 2)
	{
		puts("Error");
		exit(1);
	}

	b = atoi(av[1]);
	if (b < 0)
	{
		puts("Error");
		exit(2);
	}

	opcodes = (unsigned char *) main; /*transform to data we see and scan*/
	i = 0;
	while (i < b)
	{
		printf("%x", *(opcodes + i));
		++i;
		if (i != b)
			putchar(' ');
		else
			puts("");
	}
	return (0);
}

