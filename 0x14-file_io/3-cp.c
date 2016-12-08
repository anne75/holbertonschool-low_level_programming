#include "holberton.h"
#include <stdio.h>

#define BUF_LENGTH 1204
#define ARG_ERROR  "Usage: cp file_from file_to"
#define FR_ERROR "Error: Can't read from file"
#define FW_ERROR "Error: Can't write to"

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
 *_printexit - print to stderr and exit
 * @flag: flag
 * @s: message
 * @file_name: file name
 * @exitnb: exit number
 */
void _printexit(int flag, char *s, char *file_name, int exitnb)
{
	if (flag == 0)
		dprintf(STDERR_FILENO, "%s\n", s);
	else
		dprintf(STDERR_FILENO, "%s %s\n", s, file_name);
	exit(exitnb);
}

/**
 * _closeerror - try to close file and error message
 * @fd: should be a file descriptor
 * Return: void
 */
void _closeerror(int fd)
{
	int i;

	i = close(fd);
	if (i == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %i\n", fd);
		exit(100);
	}
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

	if (ac != 3)
		_printexit(0, ARG_ERROR, NULL, 97);
	fr = open(av[1], O_RDONLY);
	if (fr == -1)
		_printexit(1, FR_ERROR, av[1], 98);
	fw = open(av[2], O_WRONLY | O_CREAT | O_TRUNC, mode);
	if (fw == -1)
	{
		_closeerror(fr);
		_printexit(1, FW_ERROR, av[2], 99);
	}
	nr = 1;
	while ((nr = read(fr, &buffer, BUF_LENGTH)) != 0)
	{
		if (nr == -1)
		{
			dprintf(STDERR_FILENO, "%s %s\n", FR_ERROR, av[1]);
			_closeerror(fw);
			_closeerror(fr);
			exit(98);
		}
		nw = write(fw, &buffer, nr);
		if (nw != nr)
		{
			dprintf(STDERR_FILENO, "%s %s\n", FW_ERROR, av[2]);
			_closeerror(fw);
			_closeerror(fr);
			exit(99);
		}
	}
	_closeerror(fw);
	_closeerror(fr);
	return (0);
}
