#include "holberton.h"
#include <stdlib.h>

/*takes into account c is \0 */
char *_strchar(char *s, char c)
{
	if (*s == c)
		return (s);
	if (*s == '\0')
		return (NULL);
	return (_strchar(s + 1, c));
}


int wildcmp(char *s1, char *s2)
{
	char *s3;
	int c;

	if (*s2 == '*')
	{
/*I have another * in s2 */
		if (*(s2 + 1) == '*')
			return (wildcmp(s1, s2 + 1));
/*I have no char in s1 matching the char in s2 after * */
		s3  = _strchar(s1, *(s2 + 1));
		if (s3 == NULL)
			return (0);
/*I have 1 or more char in s1 matching the char in s2 */
		c = wildcmp(s3, s2 + 1);
		if (c == 1)
			return (c);
		return (wildcmp(s3 + 1, s2));

	}

	if (*s1 == '\0' && *s2 == '\0')
		return (1);

	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));

	return (0);
}
