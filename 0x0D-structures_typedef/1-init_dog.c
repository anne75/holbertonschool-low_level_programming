#include "dog.h"


/**
 * init_dog - initialize a dog
 * @d: dog struct
 * @name: name of dog
 * @age: age of dog
 * @owner: parent of dog
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{

	if (d == NULL)
		return;
	d->name = name;
	d->age = age;
	d->owner = owner;
}
