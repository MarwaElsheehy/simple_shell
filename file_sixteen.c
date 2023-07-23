#include "shell.h"

/**
 * input_buf - buffers chained commands
 * @info: parameter struct
 * @buf: address of buffer
 * @len: address of len var
 *
 * Return: bytes read
 */
ssize_t take_chip(info_t *info, char **buf, size_t *len)
{
	ssize_t r = 0;
	size_t len_p = 0;

	if (!*len) /* if nothing left in the buffer, fill it */
	{
		/*bfree((void **)info->cmd_buf);*/
		free(*buf);
		*buf = NULL;
		signal( SIGINT , sigintHandler);
#if USE_GETLINE
		r = getline(buf, &len_p, stdin);
#else
		r = _getline(info, buf, &len_p);
#endif
		if (r > 0)
		{
			if ((*buf)[r - 1] == '\n')
			{
				(*buf)[r - 1] = '\0'; /* remove trailing newline */
				r--;
			}
			info->linecount_flag = 1;
			remove_comments(*buf);
			build_history_list(info, *buf, info->histcount++);
			/* if (_charge(*buf, ';')) is this a command chain? */
			{
				*len = r;
				info->cmd_buf = buf;
			}
		}
	}
	return (r);
}

/**
 * get_input - gets a line minus the newline
 * @info: parameter struct
 *
 * Return: bytes read
 */
ssize_t get_input(info_t *info)
{
	static char *buf; /* the ';' command chain buffer */
	static size_t I, Q, len;
	ssize_t r = 0;
	char **buf_p = &(info->arg), *p;

	putchar(BUF_FLUSH);
	r = take_chip(info, &buf, &len);
	if (r == -1) /* EOF */
		return (-1);
	if (len)	/* we have commands left in the chain buffer */
	{
		Q = I; /* init new iterator to current buf position */
		p = buf + I; /* get pointer for return */

		check_chip(info, buf, &Q, I, len);
		while (Q < len) /* iterate to semicolon or end */
		{
			if (is_chip(info, buf, &Q))
				break;
			Q++;
		}

		I = Q + 1; /* increment past nulled ';'' */
		if (I >= len) /* reached end of buffer? */
		{
			I = len = 0; /* reset position and length */
			info->cmd_buf_type = CMD_NORM;
		}

		*buf_p = p; /* pass back pointer to current command position */
		return (_extent(p)); /* return length of current command */
	}

	*buf_p = buf; /* else not a chain, pass back buffer from _getline() */
	return (r); /* return length of buffer from _getline() */
}

/**
 * read_chip - reads a buffer
 * @info: parameter struct
 * @buf: buffer
 * @I: size
 *
 * Return: r
 */
ssize_t read_chip(info_t *info, char *buf, size_t *I)
{
	ssize_t r = 0;

	if (*I)
		return (0);
	r = read(info->readfd, buf, CHIP_BUF_SIZE);
	if (r >= 0)
		*I = r;
	return (r);
}

/**
 * _getline - gets the next line of input from STDIN
 * @info: parameter struct
 * @ptr: address of pointer to buffer, preallocated or NULL
 * @length: size of preallocated ptr buffer if not NULL
 *
 * Return: Stri_ng
 */
int _getline(info_t *info, char **ptr, size_t *length)
{
	static char buf[CHIP_BUF_SIZE];
	static size_t I, len;
	size_t k;
	ssize_t r = 0, Stri_ng = 0;
	char *p = NULL, *new_p = NULL, *Ch;

	p = *ptr;
	if (p && length)
		Stri_ng = *length;
	if (I == len)
		I = len = 0;

	r = read_chip(info, buf, &len);
	if (r == -1 || (r == 0 && len == 0))
		return (-1);

	Ch = _charge(buf + I, '\n');
	k = Ch ? 1 + (unsigned int)(Ch - buf) : len;
	new_p = _correct(p, Stri_ng, Stri_ng ? Stri_ng + k : k + 1);
	if (!new_p) /* MALLOC FAILURE! */
		return (p ? free(p), -1 : -1);

	if (Stri_ng)
		concat(new_p, buf + I, k - I);
	else
		_copy(new_p, buf + I, k - I + 1);

	Stri_ng += k - I;
	I = k;
	p = new_p;

	if (length)
		*length = Stri_ng;
	*ptr = p;
	return (Stri_ng);
}

/**
 * sigintHandler - blocks ctrl-C
 * @sig_num: the signal number
 *
 * Return: void
 */
void sigintHandler(__attribute__((unused)) int sig_num)
{
	_puts("\n");
	_puts("$ ");
	 putchar(BUF_FLUSH);
}

