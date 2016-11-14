#include "dog.h"
#include <stdlib.h>

/**
 * _strlen - I cannot use strlen()
 * @s: string
 * Return: return size of string
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
 * _strdup - returns a pointer to a newly allocated space in memory
 * @str: string to copy to new space in memory
 * returns a pointer to a newly allocated space in memory, which contains
 * a copy of the string given as a parameter.
 * Return: a pointer to the duplicated string. NULL if insufficient memory
 */
char *_strdup(char *str)
{
	int l, i;
	char *s;

	if (str == NULL)
		return (NULL);
	l = _strlen(str);
	s = malloc((l + 1) * sizeof(char));
	if (s == NULL)
		return (NULL);

	i = 0;
	while (i <= l)
	{
		*(s + i) = *(str + i);
		i++;
	}
	return (s);
}

/**
 * new_dog - create a new dog
 * @name: name of dog
 * @age: age of dog
 * @owner: parent of dog
 * Return: pointer to dog
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *adog;

	adog = malloc(sizeof(struct dog));
	if (adog == NULL)
		return (NULL);

	adog->name = _strdup(name);
	adog->age = age;
	adog->owner = _strdup(owner);

	return (adog);
}
