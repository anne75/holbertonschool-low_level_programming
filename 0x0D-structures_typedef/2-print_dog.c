#include <stdio.h>
#include "dog.h"

#define CHECK(x) ((x == NULL) ? "(nil)": (x))

void print_dog(struct dog *d)
{
	if (d == NULL)
		return;

	printf("Name: %s\n", CHECK(d->name));
	printf("Age: ");
	if (d->age == 0)
		puts("(nil)");
	else
		printf("%.2f\n", d->age);
	printf("Owner: %s\n", CHECK(d->owner));
}
