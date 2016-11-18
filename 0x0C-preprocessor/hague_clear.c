#include <stdlib.h>
#include <stdio.h>

int _DAH(int);

char code[]="ETIANMSURWDKGOHVFaLaPJBXCYZQb54a3d2f16g7c8a90l?e'b.s;i,d:";

int main(void)
{
	char *line, *letter, *code_copy;
	char *gets(char *);
	char value, upper_case;

	for (line = malloc(81); gets(line) != NULL; putchar('\n'))
	{

		for (letter = line; *letter; letter++)
		{
			code_copy = code;
			upper_case = (*letter >= 'a' ? *letter - 'a' + 'A' : *letter);
			value = 2;
			while (*code_copy && (*code_copy != upper_case))
			{
				value += (*code_copy >='a' ? *code_copy - 'a': 0);
				value++;
				code_copy++;
			}
			putchar(*code_copy ? _DAH(value) : '?');
			putchar(' ');
		}
	}
}

int _DAH(int letter)
{
	putchar(letter > 3 ?_DAH (letter>>1): '\0');
	return (letter & 1 ? '-' : '.');
}
