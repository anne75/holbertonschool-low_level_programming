#include <stdlib.h>

/**
 * _calloc - allocates memory for an array, initializes values to 0
 * @nmemb: number of elements
 * @size: size of each element
 * Return: pointer to array if success, or NULL
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int i;
	void *p;
	char *s;

	if (nmemb == 0 || size == 0)
		return (NULL);

	p = malloc(size * nmemb);
	if (p == NULL)
		return (NULL);
	s = p;
	i = 0;
	while (i < nmemb)
		*(s + i++) = 0;

	return (p);
}

/*http://unix.superglobalmegacorp.com/BSD4.4/newsrc/stand/bzero.c.html*/
