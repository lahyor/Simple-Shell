#include "shell.h"

/**
 * main - Entry point
 * Return: EXIT_SUCCESS
 */
int main(void)
{
	char *insert;
	char **args;
	int stats;
	
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, handle_sigquit);
	signal(SIGTSTP, handle_sigtstp);
	
	do {
		insert = get_insert();
		if (!insert || !*insert)
			break;

		args = tokenize_insert(insert);
		if (!args || !*args)
		{
			free(input);
			free_tokens(args);
			continue;
		}
		stats = execute(args);
		free(insert);
		free_tokens(args);
		
		stats = 1;
	} while (stats);

	return (EXIT_SUCCESS);
}
