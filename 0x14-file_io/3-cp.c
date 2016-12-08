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
 * _closeerror - try to close file and error message
 * @fd: should be a file descriptor
 * Return: 0 on success, -1 on failure
 */
int _closeerror(int fd)
{
	int i;

	i = close(fd);
	if (i == -1)
	{
		dprintf(2, "Error: Can't close fd %i\n", fd);
		return (-1);
	}
	return (0);
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
	mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;

/*	char *arg_error = "Usage: cp file_from file_to\n";*/
	char *fr_error = "Error: Can't read from file";
	char *fw_error = "Error: Can't write to";

	if (ac != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fr = open(av[1], O_RDONLY);
	if (fr == -1)
	{
		dprintf(STDERR_FILENO, "%s %s\n", fr_error,  av[1]);
/*		perror("");*/
		exit(98);
	}
	fw = open(av[2], O_WRONLY | O_CREAT | O_TRUNC, mode);
	if (fw == -1)
	{
		dprintf(STDERR_FILENO, "%s %s\n", fw_error, av[2]);
		exit(99);
	}
	nr = read(fr, &buffer, BUF_LENGTH);
	while (nr > 0)
	{
		nw = write(fw, &buffer, nr);
		if (nw != nr)
		{
			dprintf(STDERR_FILENO, "%s %s\n", fw_error, av[2]);
			if (_closeerror(fw) == -1 || _closeerror(fr) == -1)
				exit(100);
			exit(99);
		}
		nr = read(fr, &buffer, BUF_LENGTH);
	}

	if (_closeerror(fw) == -1 || _closeerror(fr) == -1)
		exit(100);

	return (0);
}
