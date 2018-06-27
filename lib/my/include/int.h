/*
** EPITECH PROJECT, 2017
** int.h by tfoubert <thomas.foubert@epitech.eu>
** File description:
** int.h file of the libMy project
*/

#ifndef INT_H
#define INT_H

/* int/my_sort_int_array.c */
void heapify(int *, int, int *);
void build_heap(int *, int, int *);
void my_sort_int_array(int *, int);
/* int/my_itos.c */
int get_length(int, int);
int get_nb_size(int, int);
char *fill_s(char *, int, int, int);
char *my_itos(int);
/* int/my_isneg.c */
int my_isneg(int);
/* int/my_atoi.c */
int my_atoi(char *);
/* int/my_swap_int.c */
void my_swap_int(int *, int *);
/* int/my_is_prime.c */
int my_is_prime(int);

#endif
