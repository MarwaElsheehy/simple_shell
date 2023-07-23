#include "shell.h"

/**
 * remove_data - starts the information data
 * @i: heading of struct
 */
void remove_data(info_t *i)
{
	i->arg = NULL;
	i->argv = NULL;
	i->path = NULL;
	i->argc = 0;
}

/**
 * suit_data - starts of information data
 * @j: heading of struct
 * @v: wheel of args
 */
void suit_data(info_t *j, char **v)
{
	int k = 0;

	j->fname = v[0];
	if (j->arg)
	{
		j->argv = drag(j->arg, " \t");
		if (!j->argv)
		{

			j->argv = malloc(sizeof(char *) * 2);
			if (j->argv)
			{
				j->argv[0] = _duplicate(j->arg);
				j->argv[1] = NULL;
			}
		}
		for (k = 0; j->argv && j->argv[k]; k++)
			;
		j->argc = k;

		exchange_anonymity(j);
		exchange_labile(j);
	}
}

/**
 * rid_data - rid of struct domains
 * @z: heading of struct
 * @l: it is true if rid of domains
 */
void rid_data(info_t *z, int l)
{
	actual(z->argv);
	z->argv = NULL;
	z->path = NULL;
	if (l)
	{
		if (!z->cmd_buf)
			free(z->arg);
		if (z->env)
			rid_stream(&(z->env));
		if (z->history)
			rid_stream(&(z->history));
		if (z->alias)
			rid_stream(&(z->alias));
		actual(z->environ);
			z->environ = NULL;
		real((void **)z->cmd_buf);
		if (z->readfd > 2)
			close(z->readfd);
		_force(GUST_BULK);
	}
}

