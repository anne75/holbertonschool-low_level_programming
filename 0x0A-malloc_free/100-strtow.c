#include <stdlib.h>

/**
 * getnbw - get number of words
 * @str: string to split
 * Return: nb of words in string
 */
int getnbw(char *str)
{
	int i, nbword;

	i = 0;
	nbword = 0;
	while (*(str + i) != '\0')
	{
		if (*(str + i) == ' ' && *(str + i + 1) != ' ' &&
		    *(str + i + 1) != '\0')
			++nbword;
	i++;
	}
	return (nbword);
}


/**
 * _strw - length of word
 * @s: string
 * Return: length of word at initial start of s
 */
int _strw(char *s)
{
	int i;

	i = 0;

	while (*(s + i) != ' ' && *(s + i) != '\0')
		++i;
	return (i);
}

/**
 * getw - extract word from string
 * @s: string
 * @dest: destination string for word
 * @l: size of string
 * Return: word at beginning of string
 */
char *getw(char *s, char *dest, int l)
{
	int i;

	i = 0;
	while (i < l)
	{
		*(dest + i) = *(s + i);
		++i;
	}
	*(dest + i) = '\0';
	return (dest);
}
/**
 * strtow - string to words strtok with ' ' delimiter
 * @str: string to split
 * Return: pointer to pointer to char
 */
char **strtow(char *str)
{
	int i, j, l, nbword;
	char **s;

	nbword = getnbw(str);
	s = malloc((nbword + 1) * sizeof(*s));
	if (s == NULL)
		return (NULL);

	i = 0;
	j = 0;
	while (i < nbword)
	{
		if (*(str + j) == ' ' && *(str + j + 1) != ' ' &&
		    *(str + j + 1) != '\0')
		{
			++j;
			l = _strw(str + j);
			s[i] = malloc((l + 1) * sizeof(**s));
			if (s[i] == NULL)
			{
				while (--i >= 0)
				{
					free(s[i]);
					free(s);
					return (NULL);
				}
			}
			s[i] = getw(str + j, s[i], l);
			++i;
			j += l - 1;
		}
		++j;
	}
	s[i] = NULL;
	return (s);
}
