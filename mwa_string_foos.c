#include "shell.h"

/**
 * _strcat - ncatenates TWO STRINGS..
 *
 * @dest: DESTINATION string..
 *
 * @src: ORIGIN string..
 * RETURN: Always 0
 */



char *_strcat(char *dest, char *src)

{
	int v, w = 0;

	for (v = 0; dest[v] != '\0'; v++)
	{
	}
	for (w = 0; src[w] != '\0'; w++)
	{
		dest[v] = src[w];
		v++;

	}
	dest[v] = '\0';
return (dest);

}
