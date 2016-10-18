/* no need for header file*/

/**
 * _abs - watered down version of abs() for integers
 * @n: integer value we want to get the absolute value of
 * return the absolute value of an integer
 * Return: abs(n)
 */
int _abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}
