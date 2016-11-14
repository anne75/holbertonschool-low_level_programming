#include <stdio.h>
#include <stdlib.h>
#include "dog.h"

#define CHECK(x) ((x == NULL) ? "(nil)" : (x))

/**
 * print_dog - print dog
 * @d: dog struct
 */
void print_dog(struct dog *d)
{
	if (d == NULL)
		return;

	printf("Name: %s\n", CHECK(d->name));
	printf("Age: %.1f\n", d->age);
	printf("Owner: %s\n", CHECK(d->owner));
}
