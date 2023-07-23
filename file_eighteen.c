#include "shell.h"

/**
 *  _though - Begins the Information of the data
 * @a: temple d arguments used to preserve a mission  model
 * Return: if success 0
 */
int _though(info_t *a)
{
	press_stream_chain(a->env);
	return (0);
}

/**
 * _takethough - transform the chain into an int
 * @b: argument include temple used to preserve of  mission  model
 * @x: a character
 *
 * Return: the value
 */
char *_takethough(info_t *b, const char *x)
{
	list_t *n = b->env;
	char *f;

	while (n)
	{
		f = begins_with(n->c, x);
		if (f && *f)
			return (f);
		n = n->close;
	}
	return (NULL);
}

/**
 *  response- The heading of Real Pointer and Zero Values
 * @g: argument include temple used to preserve of  mission  model
 *  Return: if success 0
 */
int response(info_t *g)
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
 * unresponse - Review if it is a deli or not
 * @m: argument include temple used to preserve of  mission  model
 *  Return: if success 0
 */
int unresponse(info_t *m)
{
	int Q;

	if (m->argc == 1)
	{
		_place("Too few arguements.\n");
		return (1);
	}
	for (1 = Q ; Q <= m->argc; Q++)
		_unsuitthough(m, m->argv[Q]);

	return (0);
}

/**
 * reside_though_streamt - Begins the Information Data
 * @p: The Argument Include temple used to preserve of  Mission  model
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

