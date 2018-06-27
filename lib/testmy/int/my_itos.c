/*
** EPITECH PROJECT, 2017
** itos
** File description:
** int to string
*/

#include <stdlib.h>

void *smalloc(size_t size);
int get_length(int nb, int length);
int get_nb_size(int nb, int size);
char *fill_s(char *s, int m, int nb, int length);

//Function that retuns a string containing the given int
char *my_itos(int nb)
{
	int length = 1;
	int size = 0;
	char *s;
	int m = 0;

	if (nb < 0) {
		m = 1;
		nb = -nb;
	}
	size = get_nb_size(nb, size);
	length = get_length(nb, length);
	s = smalloc(sizeof(char) * (size + m + 1));
	s = fill_s(s, m, nb, length);
	return (s);
}

int get_length(int nb, int length)
{
	while (nb >= 10) {
		nb /= 10;
		length *= 10;
	}
	return (length);
}

int get_nb_size(int nb, int size)
{
	while (nb >= 1) {
		nb /= 10;
		size++;
	}
	return (size);
}

char *fill_s(char *s, int m, int nb, int length)
{
	int i = 0;

	if (m == 1) {
		s[i] = '-';
		i++;
	}
	while (length >= 1) {
		s[i] = (nb / length) % 10 + '0';
		length /= 10;
		i++;
	}
	s[i] = '\0';
	return (s);
}
