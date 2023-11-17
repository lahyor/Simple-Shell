#include "shell.h"

/**
 * main - Entry point
 * Return: Always 0 (success)
 */

int main(void)
{
	char *insert;
	char **args;
	char stats;

	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, handle_sigquit);
	signal(SIGTSTP, handl_sigtstp);

	do {
		insert  = get_insert();
		if (!insert || !*insert)
			break;

		args = tokenize_insert(insert);
		if (!args || !*args)
		{
			free(insert);
			free_token(args);
			continue;
		}
		stats = execute(args);
		free(insert);
		free_token(args);

		stats = 1;
	} while (stats);

	return (EXIT_SUCCESS);
}
