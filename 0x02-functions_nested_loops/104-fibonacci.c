#include <stdio.h>
#include "holberton.h"

#define CUT 10000000

/**
 * main - entry point display fibonacci sequence up to 98th value
 * I cut my numbers arbitraryly at 10000000 and deal with 2 numbers instead of
 * one, the front par and the back part
 * Return: 0
 */
int main(void)
{
	int i, r;
	long int tmp0front, tmp1front, tmp2front, tmp0back, tmp1back, tmp2back;

	i = 2;
	tmp0back = 1;
	tmp1back = 2;
	tmp0front = 0;
	tmp1front = 0;
	r = 0;
	printf("%li, %li, ", tmp0back, tmp1back);
	while (i < 98)
	{
		tmp2back = tmp0back + tmp1back;
		if ((tmp2back / CUT) > 0)
		{
			r = tmp2back / CUT;
			tmp2back = tmp2back % CUT;
		}
		tmp2front = tmp0front + tmp1front + r;
		if (tmp2front > 0)
			printf("%li%07li", tmp2front, tmp2back);
		else
			printf("%li", tmp2back);
		tmp0front = tmp1front;
		tmp1front = tmp2front;
		tmp0back = tmp1back;
		tmp1back = tmp2back;
		r = 0;
		if (i < 97)
			printf(", ");
		i++;
	}
	printf("\n");

	return (0);
}
