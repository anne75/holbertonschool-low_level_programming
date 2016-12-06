
/**
 * helper - return number of non 0 bits in a number
 * @n: number
 * Return: number of non 0 bits
 */
int helper(unsigned long int n)
{
	int count;

	count = 0;
	while (n > 0)
	{
		if (n & 1)
			++count;
		n = n >> 1;
	}
	return (count);
}

/**
 * flip_bits - return number of bits to flip
 * @n: a number
 * @m: a number
 *  - return the number of bits to flip to go from n to m
 * Return: number of bits
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int count;

	count = 0;
	while (n || m)
	{
/*compare last bits*/
		if ((n & 1) != (m & 1))
			++count;
/*shift m and n one bit to the right*/
		n = n >> 1;
		m = m >> 1;
	}
/*n and m might have different length in number of non 0 bits*/
	count += helper(n) + helper(m);
	return (count);
}


/*I divide the task in 2
 *as long as numbers n and m are > 0 I compare their
 *last bit, and then I shift the numbers by 1 to the right
 *pretty much at each loop I divide the number by 2
 *then I reach a point where n or/and m are 0, so I need
 *to compute the number of bits == 1 in the rest of the number
 */
