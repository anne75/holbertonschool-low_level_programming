#include "holberton.h"
#include <stdio.h>

#define BUF_LENGTH 1024

/**
 * _strlen - get length of string
 * @s: a string
 * Return: length of string
 */
int _strlen(char *s)
{
	int l;

	if (!s)
		return (0);
	for (l = 0; *(s + l); ++l)
		;
	return (l);
}


/**
 * main - copy content of a file to another file
 * @ac: number of arguments passed
 * @av: array of arguments passed as a string array
 * cf cp command in bash
 * Return: always 0
 */
int main(int ac, char **av)
{
	int fr, fw, nr, nw;
	char buffer[BUF_LENGTH];

	char *arg_error = "Usage: cp file_from file_to\n";
	char *fr_error = "Error: Can't read from file";
	char *fw_error = "Error: Can't write to";

	if (ac != 3)
	{
		write(2, arg_error, _strlen(arg_error));
		exit(97);
	}

	fr = open(av[1], O_RDONLY);
	if (fr == -1)
	{
		dprintf(2, "%s %s\n", fr_error,  av[1]);
		exit(98);
	}
	fw = open(av[2], O_WRONLY | O_CREAT, 0664);
	if (fw == -1)
	{
		dprintf(2, "%s %s\n", fw_error, av[2]);
		exit(99);
	}
	nr = read(fr, &buffer, BUF_LENGTH);
	while (nr > 0)
	{
		nw = write(fw, &buffer, nr);
		if (nw != nr)
			dprintf(2, "Houston, we have a problem\n");
		nr = read(fr, &buffer, BUF_LENGTH);
	}
	close(fr);
	close(fw);
	return (0);
}
