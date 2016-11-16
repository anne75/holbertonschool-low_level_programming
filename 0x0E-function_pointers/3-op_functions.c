
/*op functions*/

/**
 * op_add - to replace +
 * @a: int
 * @b: int
 * Return: sum
 */
int op_add(int a, int b)
{
	return (a + b);
}

/**
 * op_sub - to replace -
 * @a: int
 * @b: int
 * Return: substraction
 */
int op_sub(int a, int b)
{
	return (a - b);
}

/**
 * op_mul - to replace *
 * @a: int
 * @b: int
 * Return: multiplcation
 */
int op_mul(int a, int b)
{
	return (a * b);
}

/**
 * op_div - to replace /
 * @a: int
 * @b: int
 * Return: division
 */
int op_div(int a, int b)
{
	if (b == 0)
		return (1000040);
/*taken care of in main but could exit here*/
	return (a / b);
}

/**
 * op_mod - to replace %
 * @a: int
 * @b: int
 * Return: modulo
 */
int op_mod(int a, int b)
{
	return (a % b);
}
