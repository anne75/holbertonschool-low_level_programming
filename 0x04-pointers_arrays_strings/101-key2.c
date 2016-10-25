#include <time.h>
#include <stdlib.h>
#include <stdio.h>


/**
 * main - entry point
 * Return: 0
 */
int main(int arg, char *argv[])
{
	int r, p;

	srand(time(NULL));
	r = rand();
	p = atoi(argv[1]);
	printf("%d", r % p);
	return (0);
}
