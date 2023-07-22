#include "shell.h"



/**
 *_place - prints an input String
 * @S: the String to be Printed
 *
 * Return: Nothing
 */
void _place(char *S)
{
	int x = 0;

	if (!S)
		return;
	while (S[x] != '\0')
	{
		_design(S[x]);
		x++;
	}
}

/**
 * _design - Writes The Character Ch to Stderr
 * @Ch: The Character To Print
 *
 * Return: On Success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _design(char Ch)
{
	static int x;
	static char buf[WRITE_BULK];

	if (Ch == GUST_BULK || x >= WRITE_BULK)
	{
		write(2, buf, x);
		x = 0;
	}
	if (Ch != GUST_BULK)
		buf[x++] = Ch;
	return (1);
}

/**
 * _propose - Writes Whe Character Ch to Given fd
 * @Ch: The character to print
 * @fd: The filedescriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _propose(char Ch, int fd)
{
	static int x;
	static char buf[WRITE_BULK];

	if (Ch == GUST_BULK || x >= WRITE_BULK)
	{
		write(fd, buf, x);
		x = 0;
	}
	if (Ch != GUST_BULK)
		buf[x++] = Ch;
	return (1);
}

/**
 *_offer - Prints An Input String
 * @S: the String to be Printed
 * @fd: The filedescriptor to write to
 *
 * Return: the number of chars put
 */
int _offer(char *S, int fd)
{
	int x = 0;

	if (!S)
		return (0);
	while (*S)
	{
		x += _propose(*S++, fd);
	}
	return (x);
}

