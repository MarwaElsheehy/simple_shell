#include "shell.h"

/**
 *_place - prints an input String
 * @str: the String to be Printed
 *
 * Return: Nothing
 */
void _place(char *str)
{
	int x = 0;

	if (!str)
		return;
	while (str[x] != '\0')
	{
		_design(str[x]);
		i++;
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
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (Ch == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (Ch != BUF_FLUSH)
		buf[i++] = Ch;
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
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (Ch == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (Ch != BUF_FLUSH)
		buf[i++] = Ch;
	return (1);
}

/**
 *_offer - Prints An Input String
 * @str: the String to be Printed
 * @fd: The filedescriptor to write to
 *
 * Return: the number of chars put
 */
int _offer(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _propose(*str++, fd);
	}
	return (i);
}

