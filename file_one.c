#include "shell.h"

/**
 * is_cmd - starts the information data
 * @i: argument include temple used to preserve of  mission  model
 * @p: string struct
 *
 * Return: Always 0
 */
int is_cmd(info_t *i, char *p)
{
	struct stat st;

	(void)i;
	if (!p || stat(p, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dup_chars - transform the chain to int
 * @r: the route chain
 * @t: begin of the pass
 * @s: end of the pass
 *
 * Return: Always 0
 */
char *dup_chars(char *r, int t, int s)
{
	static char buf[1024];
	int j = 0, k = 0;

	for (k = 0, j = t; j < s; j++)
		if (r[j] != ':')
			buf[k++] = r[j];
	buf[k] = 0;
	return (buf);
}

/**
 * find_path - review if it is a deli or not
 * @i: review of the chain
 * @r: the route of chain
 * @c: to be found
 *
 * Return: Always 0
 */
char *find_path(info_t *i, char *r, char *c)
{
	int j = 0, curr_pos = 0;
	char *path;

	if (!r)
		return (NULL);
	if ((_strlen(c) > 2) && starts_with(c, "./"))
	{
		if (is_cmd(j, c))
			return (c);
	}
	while (1)
	{
		if (!r[j] || r[j] == ':')
		{
			path = dup_chars(r, curr_pos, j);
			if (!*path)
				_strcat(path, c);
			else
			{
				_strcat(path, "/");
				_strcat(path, c);
			}
			if (is_cmd(j, path))
				return (path);
			if (!r[j])
				break;
			curr_pos = j;
		}
		j++;
	}
	return (NULL);
}
