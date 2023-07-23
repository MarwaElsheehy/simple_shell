#include "shell.h"

/**
 **_copy - copies a string
 *@De: the Destination String to Be Copied To
 *@Sourse: The sOurce sTring
 *@n: tHe aMount of Characters to Be coPied
 *Return: the concatenated string
 */
char *_copy(char *De, char *Sourse, int n)
{
	int I, Q;
	char *Stri_ng = De;

	I = 0;
	while (Sourse[I] != '\0' && I < n - 1)
	{
		De[I] = Sourse[I];
		I++;
	}
	if (I < n)
	{
		Q = I;
		while (Q < n)
		{
			De[Q] = '\0';
			Q++;
		}
	}
	return (Stri_ng);
}

/**
 **concat - Merge Two Strings 
 *@De: the First String
 *@Sourse: the Second String
 *@n: the Amount Of Bytes to Be Maximally Used
 *Return: the ConcaTenated String
 */
char *concat(char *De, char *Sourse, int n)
{
	int I, Q;
	char *Stri_ng = De;

	I = 0;
	Q = 0;
	while (De[I] != '\0')
		I++;
	while (Sourse[Q] != '\0' && Q < n)
	{
		De[I] = Sourse[Q];
		I++;
		Q++;
	}
	if (Q < n)
		De[I] = '\0';
	return (Stri_ng);
}

/**
 **_charge - PUT A Character In a String
 *@Stri_ng: the String To Be Parsed
 *@Ch: the Character To Look For
 *Return: (Stri_ng) a pointer to The memory area Stri_ng
 */
char *_charge(char *Stri_ng, char Ch)
{
	do {
		if (*Stri_ng == Ch)
			return (Stri_ng);
	} while (*Stri_ng++ != '\0');

	return (NULL);
}

