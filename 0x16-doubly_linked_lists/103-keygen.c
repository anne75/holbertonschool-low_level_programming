#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * f2 - p 1
 * @name: name
 * @len: length of name
 * @flag: diff between f2 and defunct f3
 * Return: int
 */
int f2(char *name, int len, int flag)
{

	int a, b;

	b = 0;

	if (flag)
	{
		a = 0;
		while (b < len)
		{
			a += name[b];
			++b;
		}
		return ((a ^ 79) & 63);
	}
	a = 1;
	while (b < len)
	{
		a *= name[b];
		++b;
	}
	return ((a ^ 85) & 63);
}

/**
 * f4 - p 3
 * @name: name
 * @len: length of name
 * Return: int
 */
int f4(char *name, int len)
{
	int a, b, r;

	a = name[0];
	b = 0;

	while (b < len)
	{
		if (name[b] > a)
			a = name[b];
		++b;
	}
	srand(a ^ 14);
	r = rand();
	return (r & 63);
}

/*return value of this function different from gdb of code*/
/**
 * f5 - p 1
 * @name: name
 * @len: length of name
 * Return: int
 */
int f5(char *name, int len)
{
	int a, b;

	a = 0;
	b = 0;

	while (b < len)
	{
		a += name[b] * name[b];
		++b;
	}
	return ((a ^ 239) & 63);
}

/*return value of this function different from gdb of code*/
/**
 * f6 - p 5
 * @letter: 1st letter of name
 * Return: int
 */
int f6(char letter)
{
	int a, b;

	a = 0;
	b = 0;

	while (b < letter)
	{
		a = rand();
		++b;
	}
	return ((a ^ 229) & 63);

}

/**
 * main - main to crackme5 find pwd for name
 * @ac: number of args
 * @av: list of args
 * Return: int
 */
int main(int ac, char **av)
{
	char *name;
	char password[7];
	int len;

	char *s1 = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";

	if (ac < 2)
		return (1);

	name = av[1];
	len = strlen(name);
	password[0] = *(s1 + ((len ^ 59) & 63));
	password[1] = *(s1 + f2(name, len, 1));
	password[2] = *(s1 + f2(name, len, 0));
	password[3] = *(s1 + f4(name, len));
	password[4] = *(s1 + f5(name, len));
	password[5] = *(s1 + f6(name[0]));
	password[6] = '\0';
	printf("%s", password);
	return (0);
}
