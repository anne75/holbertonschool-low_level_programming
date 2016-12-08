#include "holberton.h"
#include <stdio.h>

/**
 * create_file - create a file with content inside
 * @filename: name of file
 * @text_content: content to put into the file
 * Return: 1 on sucess -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int fd, l, nw;

	if (!filename)
		return (-1);

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd == -1)
		return (-1);

	if (!text_content)
	{
		close(fd);
		return (1);
	}
/*get string length*/
	for (l = 0; *(text_content + l) != '\0'; ++l)
		;

	nw = write(fd, text_content, l);
	if (nw == -1 || close(fd) == -1 || nw != l)
	{
		return (-1);
	}
	return (1);
}

