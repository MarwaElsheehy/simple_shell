#include "shell.h"

/**
 * compile - main Shell Loop
 * @info: The Parameter & Return Info Struct
 * @xv: The argument Vector from main()
 *
 * Return: 0 on success, 1 on error, or error code
 */
int compile(info_t *info, char **xv)
{
	ssize_t x = 0;
	int Builtin_Ret = 0;

	while (x != -1 && Builtin_Ret != -2)
	{
		clear_info(info);
		if (ِActiveWin(info))
			_puts("$ ");
		_eputchar(BUF_FLUSH);
		x = get_input(info);
		if (x != -1)
		{
			set_info(info, xv);
			Builtin_Ret = detect_formation(info);
			if (Builtin_Ret == -1)
				detect_lead(info);
		}
		else if (ِActiveWin(info))
			_putchar('\n');
		free_info(info, 0);
	}
	write_history(info);
	free_info(info, 1);
	if (!ِActiveWin(info) && info->status)
		exit(info->status);
	if (Builtin_Ret == -2)
	{
		if (info->err_num == -1)
			exit(info->status);
		exit(info->err_num);
	}
	return (Builtin_Ret);
}

/**
 * detect_formation - Finds a Builtin Command
 * @info: The Parameter & return Info struct
 *
 * Return: -1 if builtin not found,
 *			0 if builtin executed successfully,
 *			1 if builtin found but not successful,
 *			-2 if builtin signals exit()
 */
int detect_formation(info_t *info)
{
	int x, built_in_ret = -1;
	builtin_table builtintbl[] = {
		{"exit", Get_Exit},
		{"env", current_env},
		{"help", Help},
		{"history", History},
		{"setenv", _mysetenv},
		{"unsetenv", _myunsetenv},
		{"cd", Change_cd},
		{"alias", _Alias},
		{NULL, NULL}
	};

	for (x = 0; builtintbl[x].type; x++)
		if (_strcmp(info->argv[0], builtintbl[x].type) == 0)
		{
			info->line_count++;
			built_in_ret = builtintbl[x].func(info);
			break;
		}
	return (built_in_ret);
}

/**
 * detect_lead - [inds a Command in PATH
 * @info: the parameter & return Info Struct
 *
 * Return: void
 */
void detect_lead(info_t *info)
{
	char *path = NULL;
	int x, k;

	info->path = info->argv[0];
	if (info->linecount_flag == 1)
	{
		info->line_count++;
		info->linecount_flag = 0;
	}
	for (x = 0, k = 0; info->arg[x]; x++)
		if (!Is_Delimeter(info->arg[x], " \t\n"))
			k++;
	if (!k)
		return;

	path = find_path(info, Get_Env(info, "PATH="), info->argv[0]);
	if (path)
	{
		info->path = path;
		spine_command(info);
	}
	else
	{
		if ((ِActiveWin(info) || Get_Env(info, "PATH=")
			|| info->argv[0][0] == '/') && is_cmd(info, info->argv[0]))
			spine_command(info);
		else if (*(info->arg) != '\n')
		{
			info->status = 127;
			print_error(info, "not found\n");
		}
	}
}

/**
 * spine_command - forks a an exec Thread To run cmd
 * @info: the parameter & return info Struct
 *
 * Return: void
 */
void spine_command(info_t *info)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		/* TODO: PUT ERROR FUNCTION */
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(info->path, info->argv, get_environ(info)) == -1)
		{
			free_info(info, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
		/* TODO: PUT ERROR FUNCTION */
	}
	else
	{
		wait(&(info->status));
		if (WIFEXITED(info->status))
		{
			info->status = WEXITSTATUS(info->status);
			if (info->status == 126)
				print_error(info, "Permission denied\n");
		}
	}
}

