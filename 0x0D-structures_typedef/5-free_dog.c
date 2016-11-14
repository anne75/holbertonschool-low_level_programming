#include "dog.h"
#include <stdlib.h>

/**
 * free_dog - free dog, rip
 * @d: dog
 */
void free_dog(dog_t *d)
{
	free(d->name);
	free(d->owner);
	free(d);
}
