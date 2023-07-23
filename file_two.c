#include "shell.h"

/**
 * compile - rid of vars of the parameters
 * @I: heading of struct
 * @v: the heading of zeros
 *
 * Return: if success 0
 */
int compile(info_t *I, char **v)
{
	ssize_t y = 0;
	int t = 0;

	while (y != -1 && t != -2)
	{
		remove_data(I);
		if (honest(I))
			_lay("$ ");
		_design(GUST_BULK);
		y = take_chip(I, NULL, NULL);
		if (y != -1)
		{
			suit_data(I, v);
			t = detect_formation(I);
			if (t == -1)
				detect_lead(I);
		}
		else if (honest(I))
			_force('\n');
		rid_data(I, 0);
	}
	boost_record(I);
	rid_data(I, 1);
	if (!honest(I) && I->status)
		exit(I->status);
	if (t == -2)
	{
		if (I->err_num == -1)
			exit(I->status);
		exit(I->err_num);
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
 * @Q: argument include temple used to preserve of  mission  model
 *
 * Return: Always 0
 */
void detect_lead(info_t *Q)
{
	char *h = NULL;
	int x, k;

	Q->path = Q->argv[0];
	if (Q->linecount_flag == 1)
	{
		Q->line_count++;
		Q->linecount_flag = 0;
	}
	for (x = 0, k = 0; Q->arg[x]; x++)
		if (!be_locate(Q->arg[x], " \t\n"))
			k++;
	if (!k)
		return;

	h = detect_route(Q, _takethough(Q, "PATH="), Q->argv[0]);
	if (h)
	{
		Q->path = h;
		spine_command(Q);
	}
	else
	{
		if ((honest(Q) || _takethough(Q, "PATH=")
			|| Q->argv[0][0] == '/') && be_lead(Q, Q->argv[0]))
			spine_command(Q);
		else if (*(Q->arg) != '\n')
		{
			Q->status = 127;
			press_false(Q, "not found\n");
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
