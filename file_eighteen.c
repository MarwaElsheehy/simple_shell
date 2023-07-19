#include "shell.h"

/**
 *  _though - starts the information data
 * @a: argument include temple used to preserve of  mission  model
 * Return: if success 0
 */
int _though(info_t *a)
{
	press_stream_chain(a->env);
	return (0);
}

/**
 * _takethough - transform the chain to int
 * @b: argument include temple used to preserve of  mission  model
 * @c: a character
 *
 * Return: the value
 */
char *_takethough(info_t *b, const char *c)
{
	list_t *n = b->env;
	char *f;

	while (n)
	{
		f = starts_with(n->str, c);
		if (f && *f)
			return (f);
		n = n->close;
	}
	return (NULL);
}

/**
 * _suitthough - the heading of real pointer and zero values
 * @g: argument include temple used to preserve of  mission  model
 *  Return: if success 0
 */
int _suitthough(info_t *g)
{
	if (g->argc != 3)
	{
		_place("Incorrect number of arguements\n");
		return (1);
	}
	if (_suitthough(g, g->argv[1], g->argv[2]))
		return (0);
	return (1);
}

/**
 * _unsuitthough - review if it is a deli or not
 * @m: argument include temple used to preserve of  mission  model
 *  Return: if success 0
 */
int _unsuitthough(info_t *m)
{
	int j;

	if (m->argc == 1)
	{
		_place("Too few arguements.\n");
		return (1);
	}
	for (j = 1; j <= m->argc; j++)
		_unsuitthough(m, m->argv[i]);

	return (0);
}

/**
 * reside_though_stream - starts the information data
 * @p: argument include temple used to preserve of  mission  model
 * Return: if success 0
 */
int reside_though_streamt(info_t *p)
{
	list_t *n = NULL;
	size_t k;

	for (k = 0; environ[k]; k++)
		put_nodule_close(&n, environ[k], 0);
	p->env = n;
	return (0);
}

