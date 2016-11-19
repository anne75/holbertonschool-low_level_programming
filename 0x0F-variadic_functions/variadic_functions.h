/*header file for 0x0F*/
#ifndef _VARIADIC_FUNCTIONS_H_
#define _VARIADIC_FUNCTIONS_H_

#include <stdarg.h>
#include <stdio.h>


/**
 * fs - struct
 * @def: either c f i or s
 * @mat: format for printf
 * @i: an int
 * @c: a char
 * @f: a float
 * @s: a string
 */
typedef struct fs
{
	char def;
	void (*mat)(va_list, char *, char *);
	char *s;
} fs;



/*question 0*/
int sum_them_all(const unsigned int n, ...);

/*question 1*/
void print_numbers(const char *separator, const unsigned int n, ...);

/*question 2*/
void print_strings(const char *separator, const unsigned int n, ...);

/*question 3*/
void print_all(const char * const format, ...);


#endif
