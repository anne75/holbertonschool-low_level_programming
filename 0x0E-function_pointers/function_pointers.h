#ifndef _FUNCTION_POINTERS_H_
#define _FUNCTION_POINTERS_H_

/*question 0*/
void print_name(char *name, void (*f)(char *));

/*question 1*/
void array_iterator(int *array, size_t size, void (*action)(int));

/*question 2*/
int int_index(int *array, int size, int (*cmp)(int));

#endif
