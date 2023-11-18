#include "shell.h"

/**
 * _getenv - Get the value of an environment variable
 * @name: Name of the environment variable
 * Return: Value of the variable or NULL if it doesn't exist
 */

char *_getenv(const char *name)
{
	char **envs;
	size_t name_line = _strlen(name);

	for (envs = environ; *envs != NULL; envs++)
	{
		if (_strncmp(*envs, name, name_line) == 0 && (*envs)[name_line] == '=')
		{
			return (&(*envs)[name_line + 1]);
		}
	}

	return (NULL);
}
