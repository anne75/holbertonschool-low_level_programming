#include <stdio.h>

/**
 * main - entry point
 * prints numbers from 0 to 99 except if multiples of 3 or 5
 * Return: 0
 */
int main(void)
{
	int i;

	i = 1;
	while (i <= 100)
	{
		if ((i % 3) != 0 && (i % 5) != 0)
			printf("%d", i);
		if ((i % 3) == 0)
			printf("Fizz");
		if ((i % 5) == 0)
			printf("Buzz");
		if (i == 100)
			printf("\n");
		else
			printf(" ");
		i++;
}
	return (0);
}
