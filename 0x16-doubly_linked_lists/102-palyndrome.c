#include <stdio.h>

/**
 * _itoa - very bare version
 * @n: number
 * @s: a string
 * I know my number is less than 6 char long
 * Return: the string containing the number
 */
char * _itoa(int n, char *s)
{
	int i, j;
	char c;

	i = 0;
	while (n > 9)
	{
		s[i++] = n % 10 + '0';
		n = n / 10;
	}
	s[i++] = n + '0';
	s[i] = '\0';
/*reverse*/
	j = 0;
	--i;
	while (j < i)
	{
		c = s[j];
		s[j] = s[i];
		s[i] = c;
		--i;
		++j;
	}
	return (s);

}

/**
 * is_palydrome - check if a string is a palyndrome
 * @s: a string
 * Return: 1 if true, 0 if false
 */
int is_palyndrome(char *s)
{
	int i, l;

/*get string length*/
	for (l = 0; *(s + l); ++l)
		;

	for (i = 0; i < l / 2; ++i)
		if (*(s + i) != *(s + l - 1 - i))
			return (0);

	return (1);
}


/**
 * main - get largest palyndrome
 *
 * Return: always 0
 */
int main(void)
{
	int a, b, pct, max;
	char try[7] = "0000001"; /*I know 999 * 999 = 998001*/

	a = 999;
	b = 999;
	max = 0;
	while(a > 1)
	{
		pct = a * b;
		_itoa(pct, try);
		if (is_palyndrome(try) && pct > max)
			max = pct;
		if (b > 1)
		{
			--b;
		}
		else
		{
			--a;
			b = a;
		}
	}
	printf("%d\n", max);
	return (0);
}
