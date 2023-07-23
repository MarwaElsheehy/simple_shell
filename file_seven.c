#include "shell.h"

/**
 * copy - A Function which copys A String
 * @X: The Destination String
 * @y: The Source String
 *
 * Return: pointer to destination
 */
char *copy(char *X, char *y)
{
	int t = 0;

	if (X == y || 0 == y)
		return (X);
	while (y[t])
	{
		X[t] = y[t];
		t++;
	}
	X[t] = 0;
	return (X);
}

/**
 * _duplicate - A function to Duplicate a String
 * @S: The String Which will  be Duplicated
 *
 * Return: pointer to the duplicated string
 */
char *_duplicate(const char *S)
{
	int Leng = 0;
	char *R;

	if (S == NULL)
		return (NULL);
	while (*S++)
		Leng++;
	R = malloc(sizeof(char) * (Leng + 1));
	if (!R)
		return (NULL);
	for (Leng++; Leng--;)
		R[Leng] = *--S;
	return (R);
}

/**
 * _lay - A function which will print the string inputted
 * @S: The String Which will be printed
 *
 * Return: Nothing
 */
void _lay(char *S)
{
	int t = 0;

	if (!S)
		return;
	while (S[t] != '\0')
	{
		_force(S[t]);
		t++;
	}
}

/**
 * _force - Send Char ch To stdout
 * @Ch: The Char Which Will Be Print
 *
 * Return: On success 1.
 * On error, -1 is returned, and error is set appropriately.
 */
int _force(char Ch)
{
	static int t;
	static char buf[WRITE_BULK_SIZE];

	if (Ch == BUF_FLUSH || t >= WRITE_BULK_SIZE)
	{
		write(1, buf, t);
		t = 0;
	}
	if (Ch != BUF_FLUSH)
		buf[t++] = Ch;
	return (1);
}

