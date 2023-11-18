#include "shell.h"

/**
 * get_line - Read input from the standard input.
 * Return: The string enter by the user.
 */

void *get_line(void)
{
	static char buffer[BUFFER_SIZE];
	static int buff_pos, buff_size;
	char *insert_str = NULL;
	char curt_char;
	int insert_line = 0;

	while (1)
	{
		if (buff_pos >= buff_size)
		{
			buff_size = read(STDIN_FILENO, buffer, BUFFER_SIZE);
			buff_pos = 0;
			if (buff_size == 0)
				return (insert_str);
			else if (buff_size < 0)
			{
				perror("read");
				return (NULL);
			}
		}

		curt_char = buffer[buff_pos];

		buff_pos++;

		if (curt_char == '\n')
		{
			insert_str = realloc(insert_str, insert_line + 1);
			insert_str[insert_line] = '\0';
			return (insert_str);
		}
		else
		{
			insert_str = realloc(insert_str, insert_line + 1);
			insert_str[insert_line] = curt_char;
			insert_line++;
		}
	}
}
