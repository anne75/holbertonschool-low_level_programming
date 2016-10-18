/*no header needed*/

/**
 * _islower - watered down version of islower()
 * @c: int value we need to check
 * returns 0 or 1 if c is not lowercase
 * Return: 0 if arg is not lowercase 1 otherwise
 */
int _islower(int c)
{
	if (c >= 97 && c <= 122)
		return (1);
	return (0);
}
