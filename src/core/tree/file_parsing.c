/*
** EPITECH PROJECT, 2017
** file_parsing.c by tfoubert <thomas.foubert@epitech.eu>
** File description:
** file_parsing.c file of the {{project_name}} project
*/

#include "libC.h"
#include "explorer.h"
#include "memory.h"

/*
** PURPOSE : Determine if the given data is from a binary of not
** PARAMS  : const void *data - data to test
**           size_t len - len of this data
** RETURNS : int - 0 if it's a text file 1 if it's a binary
*/
int is_binary(const void *data, size_t len)
{
	return (memchr(data, '\0', len) != NULL);
}

/*
** PURPOSE : Function that heuristically determines the type of a file from
**           it's content
** PARAMS  : char *name - Name of the file to test
**           int len_to_read - Number of readed bytes used to detect the type
** RETURNS : int - ascii based file : F_TEXT 1
**           (WIP)image based file : F_IMG 2
**           binary based file : F_BIN 3
*/
int get_file_type(char *name, int len_to_read)
{
	FILE *filep = fopen(name, "r");
	char *buf = (char *)smalloc(sizeof(char) * (len_to_read + 1));

	fread(buf, 1, len_to_read, filep);
	fclose(filep);
	if (!is_binary(buf, len_to_read)) {
		free(buf);
		return (F_TEXT);
	}
	free(buf);
	return (F_BIN);
}
