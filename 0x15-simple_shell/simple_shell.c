#include "shell.h"
#include <stdio.h>


/**
 * main - read a line
 *
 * Return: always 0
 */
int main(void)
{
	char *line;
	char **args;
	pid_t childpid;
	int status;
	int i;

	while (1)
	{
		printf("%s %i\n", __FILE__, __LINE__);
		line = prompt();
		if (line == NULL)
		{
			printf("simple shell: prompt did not work\n");
			return (-1);
		}
/*should get basename*/
		printf("simple shell: The line is %s\n", line);
		args = strtow(line, ' ');
		if (args == NULL)
		{
			printf("simple shell: strtow ran into error\n");
			exit(98);
		}
		for(i = 0; args[i] != NULL; ++i)
			printf("-%s-",args[i]);
		puts("");
		childpid = fork();
		if (childpid == 0)
		{
			printf("simple shell: in child process\n");
			if (execve(args[0], (char *const *) args, NULL) == -1)
			{
				perror("Error:");
			}
		}
		else
		{
			waitpid(childpid, &status, 0);
			printf("in parent: child process is %u\n", childpid);
		}
	}
	return (0);
}
