#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_

/*header file for 0x14*/
/*header for write, read close*/
#include <unistd.h>
/*header for open*/
#include <fcntl.h>

/*for main*/
#include <stdlib.h>

/*the sempiternal*/
int _putchar(char);

/*question 0*/
ssize_t read_textfile(const char *filename, size_t letters);

/*question 1*/
int create_file(const char *filename, char *text_content);

/*question 2*/
int append_text_to_file(const char *filename, char *text_content);


#endif
