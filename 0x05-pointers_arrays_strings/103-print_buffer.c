#include "holberton.h"
#include <stdio.h>



int _min(int a, int b)
{
	if (a <= b)
		return a;
	return b;
}

char printable(char a)
{
	if (a >= ' ' && a <= '~')
		return (a);
	return ('.');
}



void print_buffer(char *b, int size)
{
	int i, j, res;

	i = 0;
	while (i < size)
	{
		printf("%08x:", i);
		res = _min(10, size - i);
		j = 0;
		while (j < res)
		{
			printf( " %02x%02x",*(b + i + j),*(b +  i + j + 1));
			j += 2;
		}
		printf(" ");
		while (j < 10)
		{
			printf( "     ");
			j += 2;
		}
		j = 0;
		while (j < res)
		{
			printf("%c", printable(*(b + i + j)));
			j++;
		}
		printf("\n");
		i += 10;
	}
}
