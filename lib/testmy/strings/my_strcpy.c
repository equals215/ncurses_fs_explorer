/*
** EPITECH PROJECT, 2017
** my_strcpy
** File description:
** thomas.foubert@epitech.eu
*/
#include <stddef.h>

char *my_strcpy(char *dest, char const *src)
{
	size_t i = 0;

	for (; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}
