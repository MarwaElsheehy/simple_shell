#include "shell.h"

/**
 * take_record_data - rid of vars of the parameters
 * @I: heading of struct
 * Return: Always 0
 */

char *take_record_data(info_t *I)
{
	char *f, *r;

	r = _takethough(I, "HOME=");
	if (!r)
		return (NULL);
	f = malloc(sizeof(char) * (_extent(r) + _extent(SILENT_FILE) + 2));
	if (!f)
		return (NULL);
	f[0] = 0;
	copy(f, r);
	_concat(f, "/");
	_concat(f, SILENT_FILE);
	return (f);
}

/**
 * boost_record - the heading of real pointer and zero values
 * @Q: a deli chain
 *
 * Return: Always 0
 */
int boost_record(info_t *Q)
{
	ssize_t d;
	char *m = take_record_data(Q);
	list_t *n = NULL;

	if (!m)
		return (-1);

	d = open(m, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(m);
	if (d == -1)
		return (-1);
	for (n = Q->history; n; n = n->close)
	{
		_offer(n->c, d);
		_propose('\n', d);
	}
	_propose(GUST_BULK, d);
	close(d);
	return (1);
}

/**
 * stay_record - suit the anonymity to the chain
 * @a: the heading of zeros
 * Return: Always 0
 */
int stay_record(info_t *a)
{
	int x, l = 0, t = 0;
	ssize_t d, r, Stri_ng = 0;
	struct stat st;
	char *u = NULL, *e = take_record_data(a);

	if (!e)
		return (0);

	d = open(e, O_RDONLY);
	free(e);
	if (d == -1)
		return (0);
	if (!fstat(d, &st))
		Stri_ng = st.st_size;
	if (Stri_ng < 2)
		return (0);
	u = malloc(sizeof(char) * (Stri_ng + 1));
	if (!u)
		return (0);
	r = read(d, u, Stri_ng);
	u[Stri_ng] = 0;
	if (r <= 0)
		return (free(u), 0);
	close(d);
	for (x = 0; x < Stri_ng; x++)
		if (u[x] == '\n')
		{
			u[x] = 0;
			erect_record_stream(a, u + l, t++);
			l = x + 1;
		}
	if (l != x)
		erect_record_stream(a, u + l, t++);
	free(u);
	a->histcount = t;
	while (a->histcount-- >= SILENT_MAX)
		tense_nodule_at_point(&(a->history), 0);
	rear_record(a);
	return (a->histcount);
}

/**
 * erect_record_stream - review if it is a deli or not
 * @v: argument include temple used to preserve of  mission  model
 * @w: a char
 * @z: a string
 *
 * Return: Always 0
 */
int erect_record_stream(info_t *v, char *w, int z)
{
	list_t *n = NULL;

	if (v->history)
		n = v->history;
	put_nodule_close(&n, w, z);

	if (!v->history)
		v->history = n;
	return (0);
}

/**
 * rear_record - the heading of real pointer and zero values
 * @p: argument include temple used to preserve of  mission  model
 *
 * Return: Always 0
 */
int rear_record(info_t *p)
{
	list_t *n = p->history;
	int g = 0;

	while (n)
	{
		n->I = g++;
		n = n->close;
	}
	return (p->histcount = g);
}

