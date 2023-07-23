#include "shell.h"

/**
 * stream_extent - Determines The Length Of linked list
 * @h: pointer To The First Node
 *
 * Return: size of list
 */
size_t stream_extent(const list_t *h)
{
	size_t I = 0;

	while (h)
	{
		h = h->next;
		I++;
	}
	return (I);
}

/**
 * stream_at_chains - returns An Array Of Strings of The List->str
 * @head: pointer to first node
 *
 * Return: array of strings
 */
char **stream_at_chains(list_t *head)
{
	list_t *node = head;
	size_t I = stream_extent(head), Q;
	char **strs;
	char *str;

	if (!head || !I)
		return (NULL);
	strs = malloc(sizeof(char *) * (I + 1));
	if (!strs)
		return (NULL);
	for (I = 0; node; node = node->next, I++)
	{
		str = malloc(_extent(node->str) + 1);
		if (!str)
		{
			for (Q = 0; Q < I; Q++)
				free(strs[Q]);
			free(strs);
			return (NULL);
		}

		str = copy(str, node->str);
		strs[I] = str;
	}
	strs[I] = NULL;
	return (strs);
}


/**
 * press_stream - Prints All The Elements of a list_t linked list
 * @h: pointer to First node
 *
 * Return: size of list
 */
size_t press_stream(const list_t *h)
{
	size_t I = 0;

	while (h)
{
		char buffer[20]; /*Adjust the buffer size as needed*/

		sprintf(buffer, "%lu", (unsigned long)h->num);
		putchar(':');
		putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		I++;
	}
	return (I);
}

/**
 * nodule_begins_to - Returns Node Whose String starts with "prefix"
 * @node: pointer To List Head
 * @prefix: String to Match
 * @Ch: The next character After prefix to match
 *
 * Return: match node or null
 */
list_t *nodule_begins_to(list_t *node, char *prefix, char Ch)
{
	char *p = NULL;

	while (node)
	{
		p = begins_with(node->str, prefix);
		if (p && ((Ch == -1) || (*p == Ch)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * take_nodule_point - gets the contents of a node
 * @head: pointer to list head
 * @node: pointer to the node
 *
 * Return: index of node or -1
 */
ssize_t take_nodule_point(list_t *head, list_t *node)
{
	size_t I = 0;

	while (head)
	{
		if (head == node)
			return (I);
		head = head->next;
		I++;
	}
	return (-1);
}

