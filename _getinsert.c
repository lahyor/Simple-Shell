#include "shell.h"

static char *last_insert;

/**
 * get_input - Read the line of input
 * Return: Pointer to a buffer.
 */

char *get_insert(void)
{
	char *insert = NULL;
	size_t insert_size = 0;
	ssize_t nrd;
	
	do {
		prompt();
		nrd = getline(&insert, &insert_size, stdin);
		
		if (nrd == -1)
		{
			free(insert);
			_puts("\n");
			return (NULL);
		}
		insert[nrd - 1] = '\0';

	} while (insert[0] == '\0' || isspace(insert[0]));

	last_insert = insert;
	return (insert);
}

/**
 * free_last_insert - Frees the most recent input entered by the user.
 * It should be called after the input string is no longer needed.
 */

void free_last_insert(void)
{
	free(last_insert);
	last_insert = NULL;
}
