#include "shell.h"

/**
 **_trail - Fills MemOry With anumber of bytes to a givin Char
 *@Stri_ng: the pointer to filled memory area
 *@b: the byte to fill *Stri_ng with
 *@n: the amount of bytes to be filled
 *Return: (Stri_ng) a pointer to the memory area Stri_ng
 */
char *_trail(char *Stri_ng, char b, unsigned int n)
{
	unsigned int I;

	for (I = 0; I < n; I++)
		Stri_ng[I] = b;
	return (Stri_ng);
}

/**
 * actual - Frees a String of strings momory 
 * @pp: string of Strings
 */
void actual(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}

/**
 * _correct - Allocate A block Of momory 
 * @ptr: pointer To Previous Malloc'ated Block
 * @old_size: byte size of the previous block
 * @new_size: byte size of the new block
 *
 * Return: pointer to da ol'block nameen.
 */
void *_correct(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}

