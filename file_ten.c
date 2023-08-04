#include "shell.h"

/**
 * real - the heading of real pointer and zero values
 * @t: the heading of zeros
 *
 * Return: if real value is 1 otherwise 0
 */
int real(void **t)
{
	if (t && *t)
	{
		free(*t);
		*t = NULL;
		return (1);
	}
	return (0);
}
