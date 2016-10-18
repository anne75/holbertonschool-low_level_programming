#include <stdio.h>
#include "holberton.h"


/**
 * main - entry point display fibonacci sequence
 *
 * Return: 0
 */
int main(void)
{
	int i;
	long int tmpa, tmpb, tmpc;

	i = 2;
	tmpa = 1;
	tmpb = 2;
	printf("%ld, %ld, ", tmpa, tmpb);
	while (i < 49)
	{
		tmpc = tmpa + tmpb;
		printf("%ld, ", tmpc);
		tmpa = tmpb;
		tmpb = tmpc;
		i++;
	}
	printf("%ld\n", tmpa + tmpb);
	return (0);
}
