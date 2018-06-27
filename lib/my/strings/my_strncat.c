/*
** EPITECH PROJECT, 2017
** my_strncat
** File description:
** thomas.foubert@epitech.eu
*/

char *my_strncat(char *dest, char const *src, int nb)
{
	int i = 0;
	int j = 0;

	for (; dest[i] != '\0'; i++);
	for (; j < nb && src[j] != '\0'; j++) {
		dest[i] = src[j];
		i++;
	}
	dest[i + 1] = '\0';
	return (dest);
}
