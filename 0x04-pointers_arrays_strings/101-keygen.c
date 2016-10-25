#include <time.h>
#include <stdlib.h>
#include <stdio.h>


/**
 * main - entry point
 * Return: 0
 */
int main(void)
{
	int r;

	srand(time(NULL));
	r = rand();

	printf("%d\n", r);
	return (0);
}
