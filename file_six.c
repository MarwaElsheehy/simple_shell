#include "shell.h"

/**
 **_strcat - copies a string
 *@dest: the Destination String to Be Copied To
 *@src: The sOurce sTring
 *@n: tHe aMount of Characters to Be coPied
 *Return: the concatenated string
 */
char *_strcat(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 **_strncat - Concatenates_Two Strings
 *@dest: the First String
 *@src: the Second String
 *@n: the Amount Of Bytes to Be Maximally Used
 *Return: the ConcaTenated String
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (s);
}

/**
 **_charge - locates A Character In a String
 *@s: the String To Be Parsed
 *@Ch: the Character To Look For
 *Return: (s) a pointer to The memory area s
 */
char *_charge(char *s, char Ch)
{
	do {
		if (*s == Ch)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
