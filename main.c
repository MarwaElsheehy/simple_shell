#include "shell.h"

/**
 * prime - the main file
 * @c: a char
 * @v: a number
 *
 * Return: Always 0
 */
int main(int c, char **v)
{
	info_t data[] = { INPUT_INT };
	int fd = 2;

	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (fd)
		: "r" (fd));

	if (c == 2)
	{
		fd = open(v[1], O_RDONLY);
		if (fd == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_place(v[0]);
				_place(": 0: Can't open ");
				_place(v[1]);
				_design('\n');
				_design(GUST_BULK);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		data->readfd = fd;
	}
	reside_though_stream(data);
	stay_record(data);
	compile(data, v);
	return (EXIT_SUCCESS);
}

