#include "shell.h"

/**
 * main - prints all arguments but the name of program
 * @ac: number of arguments
 * @av: list of arguments
 * Return: always 0
 */
int main(int ac, char **av)
{
	int i;
	(void) ac;

	for (i = 1; av[i] != NULL; ++i)
	{
		write(1, av[i], _strlen(av[i]));
		write(1, "\n", 1);
	}

	return (0);
}
