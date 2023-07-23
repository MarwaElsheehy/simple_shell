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
 * @v: a character
 * @d: a pointer
 *
 * Return: Always 0
 */
int _propose(char v, int d)
{
	static int k;
	static char u[WRITE_BULK];

	if (v == GUST_BULK || k >= WRITE_BULK)
	{
		write(d, u, k);
		k = 0;
	}
	if (v != GUST_BULK)
		u[k++] = v;
	return (1);
}

/**
 *_offer - the heading of real pointer and zero values
 * @t: argument include temple used to preserve of  mission  model
 * @z: The filedescriptor to write to
 *
 * Return: the number of chars put
 */
int _offer(char *t, int z)
{
	int w = 0;

	if (!t)
		return (0);
	while (*t)
	{
		w += _propose(*t++, z);
	}
	return (w);
}

