#ifndef _SHELL_H_
#define _SHELL_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


#define BUF_LENGTH 64
/*#define EOF (-1)*/

/* structs */

/**
 * path_s - node for the path linked list
 * @path: a string containing the path
 * @next: pointer to next node
 */
typedef struct path_s
{
	char *path;
	struct path_s *next;
} path_t;


ssize_t _getline(char **, size_t *);

/* in helper_string*/
int _strlen(const char *);
int check_first(char *, const char*);
char *_strdup(const char *str);
char *_memcpy(char *dest, const char *src, unsigned int n);

/*in helper_list*/
path_t *add_node_end(path_t **head, const char *str);
void free_list(path_t *head);

/*in environment*/
char *_getenv(const char *name);
void print_path(void);
path_t *link_path(path_t **head);
int _setenv(const char *name, const char *value, int overwrite);
int _setenv(const char *name, const char *value, int overwrite);

/*in strtow*/
char **strtow(char *str, char delimeter);
void free_strtow(char **s);



#endif
