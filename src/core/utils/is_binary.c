/*
** EPITECH PROJECT, 2017
** is_binary.c by tfoubert <thomas.foubert@epitech.eu>
** File description:
** is_binary.c file of the {{project_name}} project
*/

#include "libC.h"

/*
** PURPOSE : Determine if the given data is from a binary of not
** PARAMS  : const void *data - data to test
**           size_t len - len of this data
** RETURNS : int - 1 if it's a text file 0 if it's a binary
*/
int is_binary(const void *data, size_t len)
{
	return (memchr(data, '\0', len) != NULL);
}
