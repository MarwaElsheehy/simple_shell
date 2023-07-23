#include "shell.h"

/**
 * be_lead - starts the information data
 * @I: argument include temple used to preserve of  mission  model
 * @p: string struct
 *
 * Return: if success 0
 */
int be_lead(info_t *I, char *p)
{
	struct stat st;

	(void)I;
	if (!p || stat(p, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * call_edge - transform the chain to int
 * @Q: the route chain
 * @k: begin of the pass 
 * @l: end of the pass
 *
 * Return: Always 0
 */
char *call_edge(char *Q, int k, int l)
{
	static char a[1024];
	int b = 0, c = 0;

	for (c = 0, b = c; b < l; b++)
		if (Q[b] != ':')
			a[c++] = Q[b];
	a[k] = 0;
	return (a);
}

/**
 * detect_route - review if it is a deli or not
 * @v: review of the chain
 * @r: the route of chain
 * @d: to be found
 *
 * Return: return 0
 */
char *detect_route(info_t *v, char *r, char *d)
{
	int g = 0, u = 0;
	char *t;

	if (!r)
		return (NULL);
	if ((_extent(d) > 2) && begins_with(d, "./"))
	{
		if (be_lead(v, d))
			return (d);
	}
	while (1)
	{
		if (!r[g] || r[g] == ':')
		{
			t = call_edge(r, u, g);
			if (!*t)
				_concat(t, d);
			else
			{
				_concat(t, "/");
				_concat(t, d);
			}
			if (be_lead(v, t))
				return (t);
			if (!r[g])
				break;
			u = g;
		}
		g++;
	}
	return (NULL);
}