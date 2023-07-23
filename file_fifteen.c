#include "shell.h"

/**
 * remove_data - starts the information data
 * @I: heading of struct
 */
void remove_data(info_t *I)
{
	I->arg = NULL;
	I->argv = NULL;
	I->path = NULL;
	I->argc = 0;
}

/**
 * suit_data - starts of information data
 * @Q: heading of struct
 * @v: wheel of args
 */
void suit_data(info_t *Q, char **v)
{
	int k = 0;

	Q->fname = v[0];
	if (Q->arg)
	{
		Q->argv = drag(Q->arg, " \t");
		if (!Q->argv)
		{

			Q->argv = malloc(sizeof(char *) * 2);
			if (Q->argv)
			{
				Q->argv[0] = _duplicate(Q->arg);
				Q->argv[1] = NULL;
			}
		}
		for (k = 0; Q->argv && Q->argv[k]; k++)
			;
		Q->argc = k;

		exchange_anonymity(Q);
		exchange_labile(Q);
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

