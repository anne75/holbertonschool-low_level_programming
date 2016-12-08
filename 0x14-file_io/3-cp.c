#include "holberton.h"
#include <stdio.h>

#define BUF_LENGTH 1204

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
 * @fd: file descriptor
 * @s: message
 * @file_name: file name
 * @exitnb: exit number
 */
void _printexit(int fd, char *s, char *file_name, int exitnb)
{
	if (fd == 0)
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
		dprintf(STDERR_FILENO, "Error: Can't close fd %i\n", fd);
	exit(100);
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

	char *arg_error = "Usage: cp file_from file_to";
	char *fr_error = "Error: Can't read from file";
	char *fw_error = "Error: Can't write to";

	if (ac != 3)
		_printexit(0, arg_error, NULL, 97);
	fr = open(av[1], O_RDONLY);
	if (fr == -1)
		_printexit(fr, fr_error, av[1], 98);
	fw = open(av[2], O_WRONLY | O_CREAT | O_TRUNC, mode);
	if (fw == -1)
		_printexit(fw, fw_error, av[2], 99);
	nr = 1;
	while (nr > 0)
	{
		nr = read(fr, &buffer, BUF_LENGTH);
		if (nr == -1)
		{
			dprintf(STDERR_FILENO, "%s %s\n", fr_error, av[1]);
			_closeerror(fw);
			_closeerror(fr);
			exit(98);
		}
		nw = write(fw, &buffer, nr);
		if (nw != nr)
		{
			dprintf(STDERR_FILENO, "%s %s\n", fw_error, av[2]);
			_closeerror(fw);
			_closeerror(fr);
			exit(99);
		}
	}
	_closeerror(fw);
	_closeerror(fr);
	return (0);
}
