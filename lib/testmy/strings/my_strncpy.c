/*
** EPITECH PROJECT, 2017
** my_strncpy
** File description:
** a function that copies n characters from a string into another
*/

char *my_strncpy(char *dest, char const *src, int n)
{
	int i = 0;

	for (; src[i] != '\0' && i < n; i++)
		dest[i] = src[i];
	if (i == n)
		dest[i] = '\0';
	return (dest);
}
