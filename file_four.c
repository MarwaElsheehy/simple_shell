#include "shell.h"

/**
 * _extent - returns The Length Of A String
 * @s: The String whose Length to Check
 *
 * Return: integer length of string
 */
int _extent(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;
	return (i);
}

/**
 * _combine - Performs Lexicogarphic Comparison of Two strangs.
 * @s1: the First Strang
 * @s2: the Second Strang
 *
 * Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */
int _combine(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * begins_with - Checks If needle Starts with haystack
 * @haystack: string to search
 * @needle: the substring to find
 *
 * Return: address of next char of haystack or NULL
 */
char *begins_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _concat - Concatenates Two Strings
 * @dest: The Destination Buffer
 * @src: The source Buffer
 *
 * Return: pointer to destination buffer
 */
char *_concat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
