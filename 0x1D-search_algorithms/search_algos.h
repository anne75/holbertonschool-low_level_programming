#ifndef _SEARCH_ALGOS_H_
#define _SEARCH_ALGOS_H_

/*libraries*/
#include <stdio.h>

/*macros*/
#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))

/*structs*/
/**
 * struct listint_s - singly linked list
 *
 * @n: Integer
 * @index: Index of the node in the list
 * @next: Pointer to the next node
 *
 * Description: singly linked list node structure
 * for Holberton project
 */
typedef struct listint_s
{
	int n;
	size_t index;
	struct listint_s *next;
} listint_t;

/**
 * struct skiplist_s - Singly linked list with an express lane
 *
 * @n: Integer
 * @index: Index of the node in the list
 * @next: Pointer to the next node
 * @express: Pointer to the next node in the express lane
 *
 * Description: singly linked list node structure with an express lane
 * for Holberton project
 */
typedef struct skiplist_s
{
	int n;
	size_t index;
	struct skiplist_s *next;
	struct skiplist_s *express;
} skiplist_t;

/*prototypes*/
/*question 0*/
int linear_search(int *array, size_t size, int value);

/*question 1*/
int binary_search(int *array, size_t size, int value);

/*question 7 or 100*/
int jump_search(int *array, size_t size, int value);

/*question 9 or 102*/
int interpolation_search(int *array, size_t size, int value);

/*question 10 or 103*/
int exponential_search(int *array, size_t size, int value);

/*question 11 or 104*/
int advanced_binary(int *array, size_t size, int value);

/*question 12 or 105*/
listint_t *jump_list(listint_t *list, size_t size, int value);

/*question 13 or 106*/
skiplist_t *linear_skip(skiplist_t *list, int value);


#endif
