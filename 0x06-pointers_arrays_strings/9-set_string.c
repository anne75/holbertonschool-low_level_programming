#include "holberton.h"

/**
 * set_string - set the value of a pointer to a char
 * @s: pointer to a pointer
 * @to: pointer to change value to
 * Change the value of a pointer by making a pointer pointing to it
 * Return: void
 */
void set_string(char **s, char *to)
{
	*s = to;
}
