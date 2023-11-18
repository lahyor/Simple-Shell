#include "shell.h"

/**
 * free_error - free allocated pointers
 * @argv: argument vector
 * @arg: the argument
 * Return: void
 */

void free_error(char *argv[], char *arg)
{
	int x;

	for (x = 0; argv[x]; x++)
		free(argv[x]);
	free(argv);
	free(arg);
	exit(EXIT_FAILURE);
}

/**
 * free_tokens - free memory allocated variable
 * @pnt: pointer to allocated memory
 * Return: void
 */

void free_tokens(char **pnt)
{
	int x;

	for (x = 0; pnt[x]; x++)
		free((pnt[x]));
	free(pnt);
}

/**
 * free_path - free global variables containing path envs
 * @environs: The environment variables
 * Return: void
 */

void free_path(char **environs)
{
	if (environs != NULL)
	{
		size_t x = 0;

		while (environs[x] != NULL)
		{
			if (_strncmp(environs[x], "PATH=", 5) == 0)
			{
				free(environs[x]);
				environs[x] = NULL;
				break;
			}
			x++;
		}
	}
}
