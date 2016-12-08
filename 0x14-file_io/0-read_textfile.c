#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

/**
 * read_textfile - reads letters from a text file prints them
 * @filename: name of file
 * @letters: number of letters to read
 * Return:number of letters it read and printed or 0 on failure
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t nr, nw;
	char *buffer;

	if (!filename)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
		return (0);


	nr = read(fd, buffer, letters);
	if (nr == -1)
		return (0);

	nw = write(1, buffer, nr);
	free(buffer);
	close(fd);
	return (nw);
}
