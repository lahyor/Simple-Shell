#include "shell.h"

/**
 * tokenize - parsing user input into arguments
 * @str: the string to be tokenized.
 * @delim: the delimiter used to split the string.
 * Return: an array of pointers or NULL if an error occurs.
 */

char **tokenize(char *str, const char *delim)
{
	char *toke = NULL;
	char **ref = NULL;
	int x = 0;

	toke = strtok(str, delim);
	while (toke)
	{
		ref = realloc(ref, sizeof(char *) * (x + 1));
		if (ref == NULL)
			return (NULL);

		ref[x] = malloc(_strlen(toke) + 1);
		if (!(ref[x]))
			return (NULL);

		_strcpy(ref[x], toke);
		toke = strtok(NULL, delim);
		x++;
	}
	ref = realloc(ref, (x + 1) * sizeof(char *));
	if (!ref)
		return (NULL);

	ref[x] = NULL;
	return (ref);
}

/**
 * tokenize_insert - splits a user input string into tokens.
 * @insert: the user input string to be tokenized
 * Return: an array of pointers or NULL if an error occurs
 */
char **tokenize_insert(char *insert)
{
	char **toke = NULL;
	char *tmp = NULL;

	tmp = _strdup(insert);
	if (tmp == NULL)
	{
		_puts("Memory allocation error\n");
		exit(EXIT_FAILURE);
	}

	toke = tokenize(tmp, " \t\r\n\a");
	free(tmp);

	return (toke);
}
