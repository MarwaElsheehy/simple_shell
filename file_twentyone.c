#include "shell.h"

/**
 * be_string _ test if current char in buffer is a chain delimeter
 * @info: the parameter struct
 * @buf: the char buffer
 * @p: address of current position in buf
 *
 * Return: 1 if chain delimeter, 0 otherwise
 */
int be_string(info_t *info, char *buf, size_t *p)
{
	size_t j = *p;

	if (buf[j] == '|' && buf[j + 1] == '|')
	{
		buf[j] = 0;
		j++;
		info->cmd_buf_type = CMD_OR 
	}
	else if (buf[j] == '&' && buf[j + 1] == '&')
	{
		buf[j] = 0;
		j++;
		info->cmd_buf_type = CMD_AND 
	}
	else if (buf[j] == ';') 
	{
		buf[j] = NULL ;
		info->cmd_buf_type = CMD_CHAIN 
	}
	else
		return (0);
	*p = j;
	return (1);
}

/**
 * review_string - checks we should continue chaining based on last status
 * @info: the parameter struct
 * @buf: the char buffer
 * @p: address of current position in buf
 * @i: starting position in buf
 * @len: length of buf
 *
 * Return: Void
 */
void review_string(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
	size_t j = *p;

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buf[i] = 0;
			j = len;
		}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buf[i] = 0;
			j = len;
		}
	}

	*p = j;
}

/**
 * exchange_anonymity - replaces an aliases in the tokenized string
 * @info: the parameter struct
 *
 * Return: 1 if replaced, 0 otherwise
 */
int exchange_anonymity(info_t *info)
{
	int i;
	list_t *node;
	char *p;

	for (i = 0; i < 10; i++)
	{
		node = nodule_begins_to(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		p = strchr(node->str, '=');
		if (!p)
			return (0);
		p = strdup(p + 1);
		if (!p)
			return (0);
		info->argv[0] = p;
	}
	return (1);
}

/**
 *  exchange_labile- replaces vars in the tokenized string
 * @info: the parameter struct
 *
 * Return: 1 if replaced, 0 otherwise
 */
int exchange_labile(info_t *info)
{
	int i = 0;
	list_t *node;
	char buffer[20];
	for (i = 0; info->argv[i]; i++)
	{
		if (info->argv[i][0] != '$' || !info->argv[i][1])
			continue;

		 
		if (!strcmp(info->argv[i], "$?"))
		{
			sprintf(buffer, "%d", info->status);
			replace_string(&(info->argv[i]), strdup(buffer));
		}
		if (!strcmp(info->argv[i], "$$"))
		{
			sprintf(buffer, "%d", getpid());
			replace_string(&(info->argv[i]), strdup(buffer));
		}

		}
		node = nodule_begins_to(info->env, &info->argv[i][1], '=');
		if (node)
		{
			replace_string(&(info->argv[i]),
				strdup(strchr(node->str, '=') + 1));
		}
		replace_string(&info->argv[i], strdup(""));
	return (0);
	}
	


/**
 * replace_string - replaces string
 * @old: address of old string
 * @new: new string
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replace_string(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}

