#include "shell.h"
#include <stdio.h>


/**
 * main - read a line
 *
 * Return: number of characters read
 */
int main(void)
{
	ssize_t nline, nwrite;
	size_t length;
	char *line;
	char **args;

	length = 11;
	line = malloc(length * sizeof(char));
	if (line == NULL)
		exit(98);

	write(1, "$ ", 2);
	while ((nline = _getline(&line, &length)) != 0)
	{
/*the problem with getline is that it grabs the newline*/
		if (nline == -1)
		{
			printf("_getline did not work\n");
			return (-1);
		}
/*should get basename*/
		printf("nline is %lu The line is %s\n", nline, line);
		args = strtow(line, ' ');
		if (args == NULL)
		{
			printf("ran int error\n");
			exit(98);
		}
		printf("the command is --%s--, the args %s\n", args[0], args[1]);
		if (execve(args[0], (char *const *) args, NULL) == -1)
		{
			perror("Error:");
		}
		nwrite = write(1, line, nline);
		if (nwrite != nline)
			return (-1);
		printf("it wrote %lu chars\n", nwrite);
		write(1, "$ ", 2);
	}
	free(line);
	return (nline);
}
