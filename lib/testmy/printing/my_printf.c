/*
** EPITECH PROJECT, 2017
** my_printf.c
** File description:
** my_printf.c file of the my_printf project
*/

#include <stdarg.h>
#include <stdio.h>
#include "printing.h"

void flag_base(char const *s, int i, va_list list)
{
	if (s[i] == 'b')
		my_put_nbrbase(va_arg(list, unsigned int), "01");
	if (s[i] == 'o')
		my_put_nbrbase(va_arg(list, unsigned int), "01234567");
	if (s[i] == 'x')
		my_put_nbrbase(va_arg(list, unsigned int), "0123456789abcdef");
	if (s[i] == 'X')
		my_put_nbrbase(va_arg(list, unsigned int), "0123456789ABCDEF");
	if (s[i] == 'S')
		my_putstr_print(va_arg(list, char *));
	if (s[i] == 'p')
		my_put_nbrp(va_arg(list, unsigned int), "0123456789abcdef");
}

void flag_with_hastag(char const *s, int i, va_list list)
{
	if (s[i] == 'o')
		my_put_nbr_oct(va_arg(list, unsigned int), "01234567");
	if (s[i] == 'x')
		my_put_nbr_hexa(va_arg(list, unsigned int),
		"0123456789abcdef");
	if (s[i] == 'X')
		my_put_nbr_hexa2(va_arg(list, unsigned int),
		"0123456789ABCDEF");
}

void flag_classic(char const *s, int i, va_list list)
{
	if (s[i] == 'c')
		my_putchar(va_arg(list, int));
	if (s[i] == 's')
		my_putstr(va_arg(list, char *));
	if (s[i] == 'd' || s[i] == 'i')
		my_put_nbr(va_arg(list, int));
	if (s[i] == 'u')
		my_put_nbr(va_arg(list, unsigned int));
}

void check_format_diese(char const *format, int i, va_list list)
{
	char *flag = "xXsSobduicsp";
	int j = 0;

	for (; flag[j] != '\0' && flag[j] != format[i]; j++);
	if (flag[j] != '\0')
		flag_with_hastag(format, i, list);
	if (flag[j] == '\0') {
		my_putchar('%');
		my_putchar('#');
		my_putchar(format[i]);
	}
}

void my_printf(char const *format, ...)
{
	va_list list;
	int i = 0;

	va_start(list, 0);
	while (format[i] != '\0') {
		if (format[i] == '%' && format[i + 1] == '#') {
			i += 2;
			check_format_diese(format, i, list);
		} else if (format[i] == '%') {
			i++;
			check_format(format, i, list);
		} else
			my_putchar(format[i]);
		i++;
	}
	va_end(list);
}
