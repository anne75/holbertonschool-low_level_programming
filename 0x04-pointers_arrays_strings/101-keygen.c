#include <time.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * _strlen - lay man version of strlen()
 *@s: pointer to char, string
 * get the length of the string in input
 * Return: length of s
 */
int _strlen(char *s)
{
	int l;

	l = 0;
	while (*(s++) != '\0')
		l++;

	return (l);
}


/**
 * randompart - do the 2/3 of the code at random
 * @total: the value our string must get
 * @count: the value our string code has
 * @s: the char values to pick from
 * @code: our password
 * @index: the index to print our new letter to the code to
 *
 * Return: int the count obtained
 */
int randompart(int total, int count, char *s, char *code, int *index)
{
	int total34, r, len;

	len = _strlen(s);
	total34 = 3 * total / 4;
	while (count < total34)
	{
		r = rand() % len;
		if (count <= total34)
		{
			*(code + *index) = *(s + r);
			count += *(s + r);
			*index += 1;
		}

	}
	return (count);
}


/**
 * looptheend - greedy approach for the end
 * @total: the value our string must get
 * @s: the char values to pick from
 * @code: our password
 * @index: the index to print our new letter to the code to
 *
 * Return: int the difference obtained, 0 is good, else is bad
 */
int looptheend(int total, char *s, char *code, int *index)
{
	int i, count;

	i = 0;

	while (s[i] != '\0')
	{
		if ((total - s[i]) > 0)
		{
			code[*index] = s[i];
			*index += 1;
			total -= s[i];
			count = looptheend(total, s, code, index);
			if (count == 0)
				return (0);
		}
		else if ((total - s[i]) == 0)
		{
			code[*index] = s[i];
			*index += 1;
			code [*index] = '\0';
			return (0);
		}
		i++;
	}
	return (-1);
}

/**
 * main - entry point
 * Return: 0
 */
int main(void)
{
	int total, count, tmp;
	int *index;
	char *s;
	char code[62];

	srand(time(NULL));
	s = "zywvutsrqponmlkjohgfedcbaZYXWVUTSRQPONMLKJIHGFEDCBA9876543210";
	total = 2772;

	tmp = 0; /*tmp is needed for index to work*/
	index = &tmp;

	count = -1;
	while (count != 0)
	{
		count = randompart(total, 0, s, code, index);
		count = looptheend(total - count, s, code, index);
	}

	printf("%s", code);
	return (0);
}
