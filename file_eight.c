#include "shell.h"

/**
 **_trail - starts the information data
 *@s: argument include temple used to preserve of  mission  model
 *@b: a char
 *@n: a number
 *Return: Always 0
 */
char *_trail(char *s, char b, unsigned int n)
{
	unsigned int j = 0;

	for (j = 0; j < n; j++)
		s[j] = b;
	return (s);
}

/**
 * actual - rid of the memory of the chain
 * @l: the chain of the string
 */
void actual(char **l)
{
	char **c = l;

	if (!l)
		return;
	while (*l)
		free(*l++);
	free(c);
}

/**
 * _correct - transform the chain to int
 * @v: argument include temple used to preserve of  mission  model
 * @e: a pointer
 * @z: a character
 *
 * Return: Always 0
 */
void *_correct(void *v, unsigned int e, unsigned int z)
{
	char *w;

	if (!v)
		return (malloc(z));
	if (!z)
		return (free(v), NULL);
	if (z == e)
		return (v);

	w = malloc(z);
	if (!w)
		return (NULL);

	e = e < z ? e : z;
	while (e--)
		w[e] = ((char *)v)[e];
	free(v);
	return (w);
}

