#include "shell.h"

static char *last_input;
/**
 * get_insert - Read lind if input from user
 * Return: Pointer to buffer
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

	last_input = insert;
	return (insert);
}

/**
 * free_last_input - frees the most recent input
 * It should be called after the input string is no longer needed
 */

void free_last_input(void)
{
	free(last_input);
	last_input = NULL;
}
