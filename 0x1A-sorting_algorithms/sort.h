#ifndef _SORT_H_
#define _SORT_H_


#include <stdio.h>
#include <stdlib.h>

/*struct for linked lists*/
/**
 * struct listint_s - Singly linked list node
 *
 * @n: Integer stored in the node
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;


/*printing functions*/
void print_list(const listint_t *list);
void print_list_rev(const listint_t *list);
void print_array(const int *array, size_t size);

/*0-bubble_sort*/
void bubble_sort(int *array, size_t size);

/*1-insertion_sort*/
void insertion_sort_list(listint_t **list);

/*2-selection_sort*/
void selection_sort(int *array, size_t size);

/*3-quick_sort*/
void quick_sort(int *array, size_t size);

/*100-shell_sort*/
void shell_sort(int *array, size_t size);

/*101-cocktail_sort*/
void cocktail_sort_list(listint_t **list);

/*102-counting_sort*/
void counting_sort(int *array, size_t size);

/*103-merge_sort*/
void merge_sort(int *array, size_t size);

/*104-heap_sort*/
void heap_sort(int *array, size_t size);


#endif
