#include "shell.h"

/**
 * ActiveWin - Returns true if shell is ActiveWin mode
 * @info: struct address
 *
 * Return: 1 if ActiveWin mode, 0 otherwise
 */
intActiveWin(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * Is_Delimeter - Checks if character is a Delimeter
 * @Ch: The char to check
 * @delim: The delimeter string
 * Return: 1 if true, 0 if false
 */
int Is_Delimeter(char Ch, char *delim)
{
	while (*delim)
		if (*delim++ == Ch)
			return (1);
	return (0);
}

/**
 *Is_An_Alphabetic - checks for alphabetic character
 *@Ch: The character to input
 *Return: 1 if Ch is alphabetic, 0 otherwise
 */

int Is_An_Alphabetic(int Ch)
{
	if ((Ch >= 'a' && Ch <= 'z') || (Ch >= 'A' && Ch <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *str_to_int - converts a string to an integer
 *@s: the string to be converted
 *Return: 0 if no numbers in string, converted number otherwise
 */

int str_to_int(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0;  s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}

