#include <stdio.h>
#include "holberton.h"


/**
 * main - prints all arguments program receives
 * @argc: number of arguments
 * @argv[]: list of arguments
 * Return: always 0
 */
int main(int argc, char *argv[])
{
	while (argc-- > 0)
		printf("%s\n",*(argv++));
	return (0);
}
