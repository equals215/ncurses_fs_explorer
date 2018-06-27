/*
** EPITECH PROJECT, 2017
** my_strdup.c
** File description:
** thomas.foubert@epitech.eu
*/
#include <stdlib.h>

int my_strlen(char const *str);
char *my_strcpy(char *dest, char const *src);

char *my_strdup(char const *src)
{
	char *str;
	size_t length;

	length = my_strlen(src);
	str = malloc((sizeof(char) * length) + 2);
	my_strcpy(str, src);
	return (str);
}
