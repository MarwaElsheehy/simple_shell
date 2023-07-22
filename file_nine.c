#include "shell.h"

/**
 * **drag - Splits a String Into Words. Repeat Delimiters Are Ignored
 * @t: the Input string
 * @r: the Delimiter String
 * Return: a pointer to an array of strings, or NULL on Failure
 */

char **drag(char *t, char *r)
{
    int x1, x2, x3, x4, n = 0;
    char **result;

    if (t == NULL || t[0] == 0)
        return NULL;

    if (!r)
        r = " ";

    for (x1 = 0; t[x1] != '\0'; x1++)
        if (!be_locate(t[x1], r) && (be_locate(t[x1 + 1], r) || !t[x1 + 1]))
            n++;

    if (n == 0)
        return NULL;

    result = malloc((1 + n) * sizeof(char *));
    if (!result)
        return NULL;

    for (x1 = 0, x2 = 0; x2 < n; x2++)
    {
        while (be_locate(t[x1], r))
            x1++;

        x3 = 0;
        while (!be_locate(t[x1 + x3], r) && t[x1 + x3])
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
            result[x2][x4] = t[x1++];

        result[x2][x4] = 0;
    }

    result[x2] = NULL;
    return result;
}

/**
 * **pull - Splits A String Into Words
 * @i: the input String
 * @j: the delimiter
 * Return: A pointer To an Array of Strings, or NULL on Failure
 */
char **pull(char *i, char j)
{
    int x1, x2, x3, x4, n = 0;
    char **result;

    if (i == NULL || i[0] == 0)
        return NULL;

    for (x1 = 0; i[x1] != '\0'; x1++)
        if ((i[x1] != j && i[x1 + 1] == j) ||
            (i[x1] != j && !i[x1 + 1]) || i[x1 + 1] == j)
            n++;

    if (n == 0)
        return NULL;

    result = malloc((1 + n) * sizeof(char *));
    if (!result)
        return NULL;

    for (x1 = 0, x2 = 0; x2 < n; x2++)
    {
        while (i[x1] == j && i[x1] != j)
            x1++;

        x3 = 0;
        while (i[x1 + x3] != j && i[x1 + x3] && i[x1 + x3] != d)
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
            result[x2][x4] = i[x1++];

        result[x2][x4] = 0;
    }

    result[x2] = NULL;
    return result;
}
