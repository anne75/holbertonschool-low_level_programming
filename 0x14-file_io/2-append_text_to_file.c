#include "holberton.h"
#include <stdio.h>

/**
 * append_text_to_file - append text to existing file
 * @filename: name of file, should exist
 * @text_content: text to append
 * Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, l, nw;

	if (!filename)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);
	printf("file descriptor %i\n", fd);
	if (!text_content)
		return (1);

/*get string length*/
	for (l = 0; *(text_content + l) != '\0'; ++l)
		;
	nw = write(fd, text_content, l);
	close(fd);
	if (nw < 0)
		return (-1);
	return (1);
}
