#include "shell.h"

/**
 * honest - turn back if shell is true
 * @not: heading of struct
 *
 * Return: if honest moode 1 otherwise 0
 */
int honest(info_t *not)
{
	return (isatty(STDIN_FILENO) && not->readfd <= 2);
}

/**
 * be_locate - review if it is a deli or not
 * @x: a character
 * @y: a deli chain
 * Return: if true 1 otherwise 0
 */
int be_locate(char x, char *y)
{
	while (*y)
		if (*y++ == x)
			return (1);
	return (0);
}

/**
 *_veritable - review if alpha char or not
 *@k: a character
 *Return: if alpha 1 otherwise 0
 */

int _veritable(int k)
{
	if ((k >= 'a' && k <= 'z') || (k >= 'A' && k <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *_untie - transform the chain to int
 *@z: the chain to be transformed
 *Return: transform to number 1 and 0 for transformed to string
 */

int _untie(char *z)
{
	int a, b = 1, c = 0, d;
	unsigned int f = 0;

	for (a = 0;  z[a] != '\0' && c != 2; a++)
	{
		if (z[a] == '-')
			b *= -1;

		if (z[a] >= '0' && z[a] <= '9')
		{
			c = 1;
			f *= 10;
			f += (z[a] - '0');
		}
		else if (c == 1)
			c = 2;
	}

	if (b == -1)
		d = -f;
	else
		d = f;

	return (d);
}

