#include "shell.h"

/**
 * compile - rid of vars of the parameters
 * @i: heading of struct
 * @v: the heading of zeros
 *
 * Return: if success 0
 */
int compile(info_t *i, char **v)
{
	ssize_t y = 0;
	int t = 0;

	while (y != -1 && t != -2)
	{
		remove_data(i);
		if (honest(i))
			_lay("$ ");
		_design(GUST_BULK);
		y = take_chip(i);
		if (y != -1)
		{
			suit_data(i, v);
			t = detect_formation(i);
			if (t == -1)
				detect_lead(i);
		}
		else if (honest(i))
			_force('\n');
		rid_data(i, 0);
	}
	boost_record(i);
	rid_data(i, 1);
	if (!honest(i) && i->status)
		exit(i->status);
	if (t == -2)
	{
		if (i->err_num == -1)
			exit(i->status);
		exit(i->err_num);
	}
	return (t);
}

/**
 * detect_formation - suit the anonymity to the chain
 * @a: review of the chain
 *
 * Return: if successn 0 otherwise 1
 */
int detect_formation(info_t *a)
{
	int b, f = -1;
	builtin_table formation[] = {
		{"exit", _outlet},
		{"env", _though},
		{"help", _assist},
		{"history", _common},
		{"setenv", response},
		{"unsetenv", unresponse},
		{"cd", _compress},
		{"alias", _anonymity},
		{NULL, NULL}
	};

	for (b = 0; formation[b].kind; b++)
		if (_combine(a->argv[0], formation[b].kind) == 0)
		{
			a->line_count++;
			f = formation[b].tsk(a);
			break;
		}
	return (f);
}

/**
 * detect_lead - review if it is a deli or not
 * @j: argument include temple used to preserve of  mission  model
 *
 * Return: Always 0
 */
void detect_lead(info_t *j)
{
	char *h = NULL;
	int x, k;

	j->path = j->argv[0];
	if (j->linecount_flag == 1)
	{
		j->line_count++;
		j->linecount_flag = 0;
	}
	for (x = 0, k = 0; j->arg[x]; x++)
		if (!be_locate(j->arg[x], " \t\n"))
			k++;
	if (!k)
		return;

	h = detect_route(j, _takethough(j, "PATH="), j->argv[0]);
	if (h)
	{
		j->path = h;
		spine_command(j);
	}
	else
	{
		if ((honest(j) || _takethough(j, "PATH=")
			|| j->argv[0][0] == '/') && be_lead(j, j->argv[0]))
			spine_command(j);
		else if (*(j->arg) != '\n')
		{
			j->status = 127;
			press_false(j, "not found\n");
		}
	}
}

/**
 * spine_command - the heading of real pointer and zero values
 * @q: argument include temple used to preserve of  mission  model
 *
 * Return: Always 0
 */
void spine_command(info_t *q)
{
	pid_t w;

	w = fork();
	if (w == -1)
	{
		
		perror("Error:");
		return;
	}
	if (w == 0)
	{
		if (execve(q->path, q->argv, take_environ(q)) == -1)
		{
			rid_data(q, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
		
	}
	else
	{
		wait(&(q->status));
		if (WIFEXITED(q->status))
		{
			q->status = WEXITSTATUS(q->status);
			if (q->status == 126)
				press_false(q, "Permission denied\n");
		}
	}
}
