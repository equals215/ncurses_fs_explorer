/*
** EPITECH PROJECT, 2017
** fct3.c
** File description:
** fct3.c file of the my_printf project
*/

#include <stdarg.h>
#include <stdio.h>
#include "printing.h"
#include "strings.h"

void my_put_nbr_hexa(int nb, char *base)
{
	int diviseur = 1;
	int result = 0;
	int size_of_base = my_strlen(base);

	if (nb < 0) {
		nb *= -1;
		write(1, "-", 1);
	}
	while ((nb / diviseur) >= size_of_base)
		diviseur *= size_of_base;
	if (nb != 0)
		my_putstr("0x");
	while (diviseur > 0) {
		result = (nb / diviseur) % size_of_base;
		my_putchar(base[result]);
		diviseur /= size_of_base;
	}
}

void my_put_nbr_hexa2(int nb, char *base)
{
	int diviseur = 1;
	int result;
	int size_of_base = my_strlen(base);

	if (nb < 0) {
		nb *= -1;
		write(1, "-", 1);
	}
	while ((nb / diviseur) >= size_of_base)
		diviseur *= size_of_base;
	if (nb != 0)
		my_putstr("0X");
	while (diviseur > 0) {
		result = (nb / diviseur) % size_of_base;
		my_putchar(base[result]);
		diviseur /= size_of_base;
	}
}

void my_put_nbr_oct(int nb, char *base)
{
	int diviseur = 1;
	int result;
	int size_of_base = my_strlen(base);

	if (nb < 0) {
		nb *= -1;
		write(1, "-", 1);
	}
	while ((nb / diviseur) >= size_of_base)
		diviseur *= size_of_base;
	if (nb != 0)
		my_putchar('0');
	while (diviseur > 0) {
		result = (nb / diviseur) % size_of_base;
		my_putchar(base[result]);
		diviseur /= size_of_base;
	}
}

void my_put_nbrbase(int nb, char *base)
{
	int diviseur = 1;
	int result;
	int size_of_base = my_strlen(base);

	if (nb < 0) {
		nb *= -1;
		write(1, "-", 1);
	}
	while ((nb / diviseur) >= size_of_base)
		diviseur *= size_of_base;
	while (diviseur > 0) {
		result = (nb / diviseur) % size_of_base;
		my_putchar(base[result]);
		diviseur /= size_of_base;
	}
}
