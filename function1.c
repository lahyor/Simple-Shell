#include "shell.h"

/**
 * _strcpy - copies a string
 * @dest: the destination
 * @src: the source
 * Return: pointer to destination
 */
char *_strcpy(char *dest, char *src)
{
	int x = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[x])
	{
		dest[x] = src[x];
		x++;
	}
	dest[x] = 0;
	return (dest);
}

/**
 * _strcat - concatenates two strings
 * @dest: the destination buffer
 * @src: the source buffer
 * Return: pointer to destination buffer
 */
char *_strcat(char *dest, const char *src)
{
	char *ref = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}

/**
 * _strdup - duplicates a string
 * @str: the string to duplicate
 * Return: pointer to the duplicated string
 */
char *_strdup(const char *str)
{
	int len = 0;
	char *ref;

	if (str == NULL)
		return (NULL);
	while (*str++)
		len++;
	ref = malloc(sizeof(char) * len + 1);
	if (!ref)
		return (NULL);
	for (len; len--;)
		ref[len] = *--str;
	return (ref);
}

/**
 * _putchars - writes the character c to stdout
 * @s: The character to be printed
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchars(char s)
{
	return (write(1, &s, 1));
}

/**
 * _strspn - a function that gets the length
 * @s: pointer to string input
 * @accept: substring prefix to look for
 * Return: the number of bytes in the initial segment
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int x, y;

	for (x = 0; s[x]; x++)
	{
		for (y = 0; accept[y]; y++)
		{
			if (s[x] == accept[y])
				break;
		}
		if (!accept[y])
			return (x);
	}

	return (x);
}
