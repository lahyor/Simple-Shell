#include "shell.h"

/**
 * find_in_path - looks for a command specified in the path
 * @command: pointer to command string
 * Return: success if found and failure if not found
 */

char *find_in_path(char *command)
{
	struct stat sl;
	int stat_ref, x;
	char buff[PATH_MAX_LENGTH], *path, *ref, **dir;

	path = get_path();
	if (!path)
		return (NULL);
	dir = tokenize(path, PATH_SEPERATE);
	if (!dir)
		return (NULL);
	for (x = 0; dir[x]; x++)
	{
		_memset(buff, 0, PATH_MAX_LENGTH);
		_strcpy(buff, dir[x]);
		_strcat(buff, "/");
		_strcat(buff, command);
		stat_ref = stat(buff, &sl);
		if (stat_ref == 0 && S_ISREG(sl.st_mode) && (sl.st_mode & S_IXUSR))
		{
			free_tokens(dir);
			ref = malloc(sizeof(char) * (strlen(buff) + 1));
			if (!ref)
				return (NULL);
			strcpy(ref, buff);
			return (ref);
		}
	}
	if (stat_ref == -1)
		free_tokens(dir);
	return (NULL);
}
