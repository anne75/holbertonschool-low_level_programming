#include <stdio.h>


/**
 * main - get biggest prime factor of given number
 * do it like stack overflow 24166478
 * no need for sieve
 * Return: 0
 */
int main(void)
{
	long int d, n;

	n = 612852475143;
	d = 2;
	while (d < n)
	{
		if ((n % d) == 0)
		{
			n = n / d;
			d--;
		}
		d++;
	}
	printf("%li\n", n);

	return (0);
}
