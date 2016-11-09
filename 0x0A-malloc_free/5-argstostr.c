#include <stdlib.h>
#include <stdio.h>


/**
 * _strlen - I cannot use strlen()
 * @s: string
 * Return: return size of string \0 excluded
 */
int _strlen(char *s)
{
	int i;

	i = 0;

	while (*(s + i) != '\0')
		i++;
	return (i);
}


/**
 * argstostr - concatenates all the arguments of program.
 * @ac: number of arguments, including name of program
 * @av: array of string arguments
 * Return: pointer to string created, all arguments together \n separated
 */
char *argstostr(int ac, char **av)
{
	int i, j, k, tot_l;
	char *s;

	if (av == NULL)
		return (NULL);
	i = 0;
	tot_l = 0;
	while (i < ac)
	{
		tot_l += _strlen(*(av + i));
		i++;
	}
	tot_l += ac + 1; /*add \n and \0*/
	s = malloc(tot_l * sizeof(char));
	if (s == NULL)
		return (NULL);

	i = 0;
	j = 0;
	while (i < ac)
	{
		k = 0;
		while (av[i][k] != '\0')
		{
			*(s + j) = av[i][k];
			++k;
			++j;
		}
		*(s + j++) = '\n';
		i++;
	}
	*(s + j) = '\0';
	return (s);
}
