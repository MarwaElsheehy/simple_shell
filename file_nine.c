#include "shell.h"

/**
 * **drag - Divide a String Into Words. Repeat Delimiters Are Ignored
 * @str: The Input String
 * @d: The Delimiter String
 * Return: a pointer to an array of strings, or NULL on Failure
 */

char **drag(char *str, char *d)
{
    int x1, x2, x3, x4, numwords = 0;
    char **result;

    if (str == NULL || str[0] == 0)
        return NULL;

    if (!d)
        d = " ";

    for (x1 = 0; str[x1] != '\0'; x1++)
        if (!Is_Delimiter(str[x1], d) && (Is_Delimiter(str[x1 + 1], d) || !str[x1 + 1]))
            numwords++;

    if (numwords == 0)
        return NULL;

    result = malloc((1 + numwords) * sizeof(char *));
    if (!result)
        return NULL;

    for (x1 = 0, x2 = 0; x2 < numwords; x2++)
    {
        while (Is_Delimiter(str[x1], d))
            x1++;

        x3 = 0;
        while (!Is_Delimiter(str[x1 + x3], d) && str[x1 + x3])
            x3++;

        result[x2] = malloc((x3 + 1) * sizeof(char));
        if (!result[x2])
        {
            for (x4 = 0; x4 < x2; x4++)
                free(result[x4]);
            free(result);
            return NULL;
        }

        for (x4 = 0; x4 < x3; x4++)
            result[x2][x4] = str[x1++];

        result[x2][x4] = 0;
    }

    result[x2] = NULL;
    return result;
}

/**
 * **pull - Divide  A String Into Words
 * @str: the input String
 * @d: the delimiter
 * Return: A pointer To an Array of Strings, or NULL on Failure
 */
char **pull(char *str, char d)
{
    int x1, x2, x3, x4, numwords = 0;
    char **result;

    if (str == NULL || str[0] == 0)
        return NULL;

    for (x1 = 0; str[x1] != '\0'; x1++)
        if ((str[x1] != d && str[x1 + 1] == d) ||
            (str[x1] != d && !str[x1 + 1]) || str[x1 + 1] == d)
            numwords++;

    if (numwords == 0)
        return NULL;

    result = malloc((1 + numwords) * sizeof(char *));
    if (!result)
        return NULL;

    for (x1 = 0, x2 = 0; x2 < numwords; x2++)
    {
        while (str[x1] == d && str[x1] != d)
            x1++;

        x3 = 0;
        while (str[x1 + x3] != d && str[x1 + x3] && str[x1 + x3] != d)
            x3++;

        result[x2] = malloc((x3 + 1) * sizeof(char));
        if (!result[x2])
        {
            for (x4 = 0; x4 < x2; x4++)
                free(result[x4]);
            free(result);
            return NULL;
        }

        for (x4 = 0; x4 < x3; x4++)
            result[x2][x4] = str[x1++];

        result[x2][x4] = 0;
    }

    result[x2] = NULL;
    return result;
}
