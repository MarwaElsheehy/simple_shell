#include "shell.h"

/**
 * hsh - rid of vars of the parameters
 * @info: heading of struct
 * @av: the heading of zeros
 *
 * Return: if success 0
 */
int hsh(info_t *info, char **av)
{
	ssize_t y = 0;
	int t = 0;

	while (y != -1 && t != -2)
	{
		remove_data(info);
		if (honest(info))
			_lay("$ ");
		_design(GUST_BULK);
		y = take_chip(info);
		if (y != -1)
		{
			suit_data(info, av);
			t = find_builtin(info);
			if (t == -1)
				find_cmd(info);
		}
		else if (honest(info))
			_force('\n');
		rid_data(info, 0);
	}
	boost_record(info);
	rid_data(info, 1);
	if (!honest(info) && info->status)
		exit(info->status);
	if (t == -2)
	{
		if (info->err_num == -1)
			exit(info->status);
		exit(info->err_num);
	}
	return (t);
}

/**
 * find_builtin - suit the anonymity to the chain
 * @info: review of the chain
 *
 * Return: if successn 0 otherwise 1
 */
int find_builtin(info_t *info)
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
		if (_combine(info->argv[0], formation[b].kind) == 0)
		{
			info->line_count++;
			f = formation[b].tsk(info);
			break;
		}
	return (f);
}

/**
 * find_cmd - review if it is a deli or not
 * @info: argument include temple used to preserve of  mission  model
 *
 * Return: Always 0
 */
void find_cmd(info_t *info)
{
	char *h = NULL;
	int x, k;

	info->path = info->argv[0];
	if (info->linecount_flag == 1)
	{
		info->line_count++;
		info->linecount_flag = 0;
	}
	for (x = 0, k = 0; info->arg[x]; x++)
		if (!be_locate(info->arg[x], " \t\n"))
			k++;
	if (!k)
		return;

	h = detect_route(info, _takethough(info, "PATH="), info->argv[0]);
	if (h)
	{
		info->path = h;
		fork_cmd(info);
	}
	else
	{
		if ((honest(info) || _takethough(info, "PATH=")
			|| info->argv[0][0] == '/') && be_lead(info, info->argv[0]))
			fork_cmd(info);
		else if (*(info->arg) != '\n')
		{
			info->status = 127;
			press_false(info, "not found\n");
		}
	}
}

/**
 * fork_cmd - the heading of real pointer and zero values
 * @info: argument include temple used to preserve of  mission  model
 *
 * Return: Always 0
 */
void fork_cmd(info_t *info)
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
		if (execve(info->path, info->argv, take_environ(info)) == -1)
		{
			rid_data(info, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}

	}
	else
	{
		wait(&(info->status));
		if (WIFEXITED(info->status))
		{
			info->status = WEXITSTATUS(info->status);
			if (info->status == 126)
				press_false(info, "Permission denied\n");
		}
	}
}
