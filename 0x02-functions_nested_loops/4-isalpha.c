/*no header needed*/

/**
 * _isalpha - watered down version of isalpha()
 * @c: input, an int that may be a letter
 * check if c is a letter
 * Return: 1 if c is a letter, 0 otherwise
 */
int _isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	return (0);
}
