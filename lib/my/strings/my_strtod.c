/*
** EPITECH PROJECT, 2017
** my_strtod.c
** File description:
** thomas.foubert@epitech.eu
*/

#include <stdlib.h>

int my_strlen(char const *str);
void *smalloc(size_t size);

char *my_strtod(char *str, char *base, char **endptr)
{
	int i = 0;
	int j = 0;
	char *nb_dest;
	int m = 0;
	int len = my_strlen(base) - 1;

	*endptr = str;
	nb_dest = (char*) smalloc(sizeof(char) * my_strlen(str) + 1);
	for (; str[i] == '-' || str[i] == '+'; i++) {
		if (str[i] == '-')
			m++;
	}
	if (m % 2 == 1) {
		nb_dest[j] = '-';
		j++;
	}
	for (; str[i] >= base[0] && str[i] <= base[len]; i++, j++)
		nb_dest[j] = str[i];
	*endptr += i;
	return (nb_dest);
}
