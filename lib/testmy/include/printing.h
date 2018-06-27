/*
** EPITECH PROJECT, 2017
** printing.h by tfoubert <thomas.foubert@epitech.eu>
** File description:
** printing.h file of the libMy project
*/

#ifndef PRINTING_H
#define PRINTING_H

#include <unistd.h>
#include <stdarg.h>

/* printing/my_putstr.c */
int my_putstr(char const *);
/* printing/my_printf.c */
void flag_base(char const *, int, va_list);
void flag_with_hastag(char const *, int, va_list);
void flag_classic(char const *, int, va_list);
void check_format_diese(char const *, int, va_list);
void my_printf(char const *, ...);
/* printing/my_printf_core2.c */
void my_put_nbr_hexa(int, char *);
void my_put_nbr_hexa2(int, char *);
void my_put_nbr_oct(int, char *);
void my_put_nbrbase(int, char *);
/* printing/my_put_nbr.c */
int my_put_nbr(int);
/* printing/my_printf_core1.c */
void my_putstr_print(char const *);
void my_put_nbrp(int, char *);
void check_format(char const *, int, va_list);
/* printing/my_putchar.c */
void my_putchar(char);

#endif
