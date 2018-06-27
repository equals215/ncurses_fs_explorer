/*
** EPITECH PROJECT, 2017
** fct2.c
** File description:
** fct2.c file of the my_printf project
*/

#include <stdarg.h>
#include <stdio.h>
#include "printing.h"
#include "strings.h"

void my_putstr_print(char const *str)
{
	int i = 0;

	for (; str[i] != '\0'; i++) {
		if (str[i] < 8) {
			my_putstr("\\00");
			my_put_nbrbase(str[i], "01234567");
			i++;
		}
		if (str[i] < 32) {
			my_putstr("\\0");
			my_put_nbrbase(str[i], "01234567");
			i++;
		}
		if (str[i] >= 126) {
			my_putchar(92);
			my_put_nbrbase(str[i], "01234567");
			i++;
		}
		my_putchar(str[i]);
	}
}

void my_put_nbrp(int nb, char *base)
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
		my_putstr("0x");
	if (nb == 0)
		my_putstr("(nil)");
	for (; diviseur > 0; diviseur /= size_of_base) {
		result = (nb / diviseur) % size_of_base;
		my_putchar(base[result]);
	}
}

void check_format(char const *format, int i, va_list list)
{
	char *flag = "xXsSobduicsp";
	int j = 0;

	if (format[i] == '%') {
		my_putchar('%');
		i++;
		j = 0;
	} else {
		for (; flag [j] != '\0' && flag[j] != format[i]; j++);
		if (flag[j] != '\0') {
			flag_base(format, i, list);
			flag_classic(format, i, list);
		}
		if (flag[j] == '\0') {
			my_putchar('%');
			my_putchar(format[i]);
		}
	}
}
