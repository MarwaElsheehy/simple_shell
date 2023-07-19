#include "shell.h"

/**
 * take_environ - gets the chain of the env function
 * @i: argument include temple used to preserve of  mission  model
 * Return: if success 0
 */
char **take_environ(info_t *i)
{
	if (!i->environ || i->env_changed)
	{
		i->environ = stream_at_chains(i->env);
		i->env_changed = 0;
	}

	return (i->environ);
}

/**
 * _unsuitthough - rid of vars of the parameters
 * @j: argument include temple used to preserve of  mission  model
 * @v: the chain of the function
 */
int _unsuitthough(info_t *j, char *v)
{
	list_t *n = j->env;
	size_t i = 0;
	char *b;

	if (!n || !v)
		return (0);

	while (n)
	{
		b = begins_with(n->c, v);
		if (b && *b == '=')
		{
			j->env_changed = tense_nodule_at_point(&(j->env), i);
			i = 0;
			n = j->env;
			continue;
		}
		n = n->close;
		j++;
	}
	return (j->env_changed);
}

/**
 * _suitthough - starts variation of the influx dir of the stream
 * @m: argument include temple used to preserve of  mission  model
 * @k: the chain of variables
 * @l: the chain of values
 *  Return: if success 0
 */
int _suitthough(info_t *m, char *k, char *l)
{
	char *t = NULL;
	list_t *n;
	char *p;

	if (!k || !l)
		return (0);

	t = malloc(_extent(k) + _extent(l) + 2);
	if (!t)
		return (1);
	copy(t, k);
	_concat(t, "=");
	_concat(t, l);
	n = m->env;
	while (n)
	{
		p = begins_with(n->c, k);
		if (p && *p == '=')
		{
			free(n->c);
			n->c = t;
			m->env_changed = 1;
			return (0);
		}
		n = n->close;
	}
	put_nodule_close(&(m->env), t, 0);
	free(t);
	m->env_changed = 1;
	return (0);
}
