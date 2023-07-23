#include "shell.h"

/**
 *_place - press of the chain
 * @r: the chain to be pressed
 *
 * Return: Always 0
 */
void _place(char *r)
{
	int i = 0;

	if (!r)
		return;
	while (r[i] != '\0')
	{
		_design(r[i]);
		i++;
	}
}

/**
 * _design - starts the information data
 * @h: a char
 *
 * Return: Always 0
 */
int _design(char h)
{
	static int j;
	static char f[WRITE_BULK];

	if (h == GUST_BULK || j >= WRITE_BULK)
	{
		write(2, f, j);
		j = 0;
	}
	if (h != GUST_BULK)
		f[j++] = h;
	return (1);
}

/**
 * _propose - transform the chain to int
 * @a: a character
 * @b: a pointer
 *
 * Return: Always 0
 */
int _propose(char a, int b)
{
	static int k;
	static char u[WRITE_BULK];

	if (a == GUST_BULK || k >= WRITE_BULK)
	{
		write(b, u, k);
		k = 0;
	}
	if (a != GUST_BULK)
		u[k++] = a;
	return (1);
}

/**
 *_offer - the heading of real pointer and zero values
 * @c: argument include temple used to preserve of  mission  model
 * @d: The filedescriptor to write to
 *
 * Return: the number of chars put
 */
int _offer(char *c, int d)
{
	int w = 0;

	if (!c)
		return (0);
	while (*c)
	{
		w += _propose(*c++, d);
	}
	return (w);
}

