#include "shell.h"

/**
 * _common - show the common stream of numbers and chains begins at 0
 * @i: argument include temple used to preserve of  mission  model
 *  Return: 0
 */
int _common(info_t *i)
{
	press_stream(i->history);
	return (0);
}

/**
 * unthough_anonymity- suit the anonymity to the chain
 * @j: model of the parameter
 * @s: the string alias the chain of anonymity
 *
 * Return: if success 1 otherwise 0
 */
int unthough_anonymity(info_t *j, char *s)
{
	char *m, n;
	int t;

	m = _charge(s, '=');
	if (!m)
		return (1);
	n = *m;
	*m = 0;
	t = tense_nodule_at_point(&(j->alias),
		take_nodule_point(j->alias, nodule_begins_to(j->alias, s, -1)));
	*m = n;
	return (t);
}

/**
 * though_anonymity - suits anonymity to the chain
 * @a: model of parameter
 * @b: the chain of anonymity
 *
 * Return: if success 1 otherwise 0
 */
int though_anonymity(info_t *a, char *b)
{
	char *d;

	d = _charge(b, '=');
	if (!d)
		return (1);
	if (!*++d)
		return (unthough_anonymity(a, b));

	unthough_anonymity(a, b);
	return (put_nodule_close(&(a->alias), b, 0) == NULL);
}

/**
 * press_anonymity- press anonymity chain
 * @n: anonymity nodule
 *
 * Return: if success 1 otherwise 0
 */
int press_anonymity(list_t *n)
{
	char *x = NULL, *y = NULL;

	if (n)
	{
		x = _charge(n->c, '=');
		for (y = n->c; y <= x; y++)
			_force(*y);
		_force('\'');
		_lay(x + 1);
		_lay("'\n");
		return (0);
	}
	return (1);
}

/**
 * _anonymity - the anonymity buildin struct
 * @l: argument include temple used to preserve of  mission  model 
 *  Return: if success 0
 */
int _anonymity(info_t *l)
{
	int q = 0;
	char *r = NULL;
	list_t *n = NULL;

	if (l->argc == 1)
	{
		n = l->alias;
		while (n)
		{
			press_anonymity(n);
			n = n->close;
		}
		return (0);
	}
	for (q = 1; l->argv[q]; q++)
	{
		r = _charge(l->argv[q], '=');
		if (r)
			though_anonymity(l, l->argv[q]);
		else
			press_anonymity(nodule_begins_to(l->alias, l->argv[q], '='));
	}

	return (0);
}

