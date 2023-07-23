#include "shell.h"

/**
 * take_environ - gets the chain of the env function
 * @I: argument include temple used to preserve of  mission  model
 * Return: if success 0
 */
char **take_environ(info_t *I)
{
	if (!I->environ || I->env_changed)
	{
		I->environ = stream_at_chains(I->env);
		I->env_changed = 0;
	}

	return (I->environ);
}

/**
 * _unsuitthough - rid of vars of the parameters
 * @Q: argument include temple used to preserve of  mission  model
 * @v: the chain of the function
 */
int _unsuitthough(info_t *Q, char *v)
{
	list_t *n = Q->env;
	size_t I = 0;
	char *b;

	if (!n || !v)
		return (0);

	while (n)
	{
		b = begins_with(n->c, v);
		if (b && *b == '=')
		{
			Q->env_changed = tense_nodule_at_point(&(Q->env), I);
			I = 0;
			n = Q->env;
			continue;
		}
		n = n->close;
		Q++;
	}
	return (Q->env_changed);
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
