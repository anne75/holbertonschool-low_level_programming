#include "shell.h"
#include <stdio.h>


/**
 * main - read a line
 *
 * Return: number of characters read
 */
int main(int ac, char **av)
{
	ssize_t nline, nwrite;
	size_t length;
	char *line;
	(void) ac;

	length = 1024;
	line = malloc(length * sizeof(char));
	if (line == NULL)
		exit(98);

	write(1, "$ ", 2);
	while ((nline = getline(&line, &length, stdin)) != 0)
	{
		if (nline == -1)
			return (-1);
		if (execve(line, av, NULL) == -1)
		{
			perror("Error:");
		}
		nwrite = write(1, line, nline);
		if (nwrite != nline)
			return (-1);
		printf("%lu\n", nwrite);
		write(1, "$ ", 2);
	}
	free(line);
	return (nline);
}
