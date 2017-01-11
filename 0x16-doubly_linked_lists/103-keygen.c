#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/**
 * f1 - p zero
 * @a: longueur name
 * Return: int
 */
int f1(int a)
{
	return ((a ^ 59) & 63);
}

/**
 * f2 - p 1
 * @name: name
 * @len: length of name
 * Return: int
 */
int f2(char *name, int len)
{

	int a, b;

	a = 0;
	b = 0;
	while (b < len)
	{
		a += name[b];
		++b;
	}
	return ((a ^ 79) & 63);
}

/**
 * f3 - p 2
 * @name: name
 * @len: length of name
 * Return: int
 */
int f3(char *name, int len)
{

	int a, b;

	a = 1;
	b = 0;
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

	char *s1 = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKI\314uk";

	if (ac != 2)
		return (1);
	if (strlen(av[1]) < 1)
		return (1);
	name = av[1];
	password[0] = *(s1 + f1(strlen(name)));
	password[1] = *(s1 + f2(name, strlen(name)));
	password[2] = *(s1 + f3(name, strlen(name)));
	password[3] = *(s1 + f4(name, strlen(name)));
	password[4] = *(s1 + f5(name, strlen(name)));
	password[5] = *(s1 + f6(name[0]));
	password[7] = '\0';
	printf("%s", password);
	return (0);
}
