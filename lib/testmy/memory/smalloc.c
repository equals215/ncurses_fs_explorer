/*
** EPITECH PROJECT, 2017
** smalloc.c by tfoubert <thomas.foubert@epitech.eu>
** File description:
** SecureMalloc function
*/

#include <stdio.h>
#include <stdlib.h>

void *smalloc(size_t size)
{
	void *ptr = malloc(size);

	if (ptr == NULL) {
		perror("malloc");
	}
	return (ptr);
}
