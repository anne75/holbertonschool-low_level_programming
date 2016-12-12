#include <unistd.h>
#include <stdlib.h>
#include "shell.h"


/**
 * flush_buffer - initialize all values to \0
 * @buffer: a char array
 * @size: size of buffer
 */
void flush_buffer(char *buffer, size_t size)
{
	if (!buffer || !size)
		return;
	while (--size >= 0)
		buffer[size] = '\0';
}

/**
 * _realloc - reallocates a memory block using malloc and free
 * @ptr: pointer to the memory previously allocated
 * @old_size: size in bytes allocated for ptr
 * @new_size: new size in bytes
 * The contents will be unchanged in the range from the start of the
 * region up  to the minimum of the old and new sizes.  If the new size
 * is larger than the old size, the added memory will not be initialized
 *. If ptr is NULL, then the call is  equivalent  to malloc(size), for
 * all  values of size; if size is equal to zero, and ptr is not NULL,
 * then the call is equivalent to free(ptr).
 * Return: pointer to new memory space, or NULL if fails
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	unsigned int min, i;
	void *new;
	char *help1, *help2;

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size == old_size)
		return (ptr);

	new = malloc(new_size);
	if (new == NULL)
		return (NULL);

	if (ptr == NULL)
		return (new);

	min = (old_size > new_size) ? new_size : old_size;
	i = 0;
	help1 = ptr;
	help2 = new;

	while (i < min)
	{
		*(help2 + i) = *(help1 + i);
		++i;
	}
	free(ptr);
	while (i < new_size) /*initialize end of new buffer*/
		*(help2 + i++) = '\0';

	return (new);
}


/**
 * check_buffer
 * @buf: pointer to buffer
 * @size: pointer to size of buffer
 * @index: index at which to enter char
 * since we need to insert '\0' at end of buffer, check we have room
 * or realloc
 * Return: pointer to buffer
 */
char *check_buffer(char *buf, size_t *size, size_t index)
{
	if (!buf || !size)
		return (NULL); /*should exit really*/
	if (index < *size -1) /*I need 2 free spots at this point*/
		return (buf);
	buf = _realloc(buf, *size, *size * 2);
	if (buf == NULL)
		return (NULL);
	*size = *size * 2;
	return (buf);
}

/**
 * _getline - read a line from standard input
 * @buf: a pointer to a buffer
 * @size: size of buffer
 * Return: number of characters read on success, -1 otherwise
 */
ssize_t _getline(char **buf, size_t *size)
{
	static size_t index;
	size_t count;
	int check_r;
	char *position;

	if (!buf || !size)
		return (-1);

	if (!*buf)
	{
		*size = BUF_LENGTH;
		*buf = malloc(*size * sizeof(char));
		if (*buf == NULL)
			return (-1);
	}
	flush_buffer(*buf, *size);
	index = 0;
	count = 0;
	position = *buf; /*saves my life for dereferencing*/
/*read all at once*/
	while ((check_r = read(STDIN_FILENO, position + index, size - 1 - index)) >= *size - 1 - index)
	{
		index += check_r + 1;
		position = _realloc(position, *size, *size * 2);
		if (position == NULL)
			return (-1);
		*size *= 2;
	}
	if (check_r == -1)
		return (-1);
/*parse the string*/
	while (1)
	{
		//commands = _strtow(position, '\n');
//?create a get_command while I do not reach the null string?//
	return (index);
}
