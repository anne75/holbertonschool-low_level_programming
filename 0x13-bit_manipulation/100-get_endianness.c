
/*
 * endianness represent the BYTE ordering of the words in computer memory
 * big-endian when most significant byte is at lowest address
 * little-endian when least significant byte at lowest address
 * check wikipedia
 */
/**
 * get_endianness - check endianness of a system
 * Return: 0 if big endian, 1 otherwise
 */
int get_endianness(void)
{
	int n;
	char *s;

	n = 1;
/*n is 4 bytes in the order 1 0 0 0 (LE)or 0 0 0 1 (BE)*/
/*convert n to a string to have access to all bytes*/
	s = (char *)&n;

	return (*s);
}
