#include "shell.h"

/**
 * _extent - A function to return the lenght to a g iven string
 * @Stri_ng: The String given to check its length
 *
 * Return: integer length of string
 */
int _extent(char *Stri_ng)
{
	int I = 0;

	if (!Stri_ng)
		return (0);

	while (*Stri_ng++)
		I++;
	return (I);
}

/**
 * _combine - compare two givin Strings
 * @Stri_ng1: the First givin Strang
 * @Stri_ng2: the Second givin Strang
 *
 * Return: negative if Stri_ng1 < Stri_ng2, positive if Stri_ng1 > Stri_ng2, zero if Stri_ng1 == Stri_ng2
 */
int _combine(char *Stri_ng1, char *Stri_ng2)
{
	while (*Stri_ng1 && *Stri_ng2)
	{
		if (*Stri_ng1 != *Stri_ng2)
			return (*Stri_ng1 - *Stri_ng2);
		Stri_ng1++;
		Stri_ng2++;
	}
	if (*Stri_ng1 == *Stri_ng2)
		return (0);
	else
		return (*Stri_ng1 < *Stri_ng2 ? -1 : 1);
}

/**
 * begins_with - checks if theres sub String in a givin String
 * @HaYstack : The String to searsh
 * @NEEDLE: the Substring we want to find to find
 *
 * Return: address of next char of HaYstack  or NULL
 */
char *begins_with(const char *HaYstack , const char *NEEDLE)
{
	while (*NEEDLE)
		if (*NEEDLE++ != *HaYstack ++)
			return (NULL);
	return ((char *)HaYstack );
}

/**
 * _concat - Merge two Givin strings
 * @De: the first givin 
 * @Sourse: The the second givin 
 *
 * Return: pointer to destination buffer
 */
char *_concat(char *De, char *Sourse)
{
	char *Rt = De;

	while (*De)
		De++;
	while (*Sourse)
		*De++ = *Sourse++;
	*De = *Sourse;
	return (Rt);
}

