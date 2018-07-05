/*
** EPITECH PROJECT, 2017
** file_details_parsing.c by tfoubert <thomas.foubert@epitech.eu>
** File description:
** file_details_parsing.c file of the {{project_name}} project
*/

#include "libC.h"
#include "explorer.h"
#include "memory.h"
#include "strings.h"

/*
** PURPOSE : Determine if the given data is from a binary of not
** PARAMS  : const void *data - data to test
** RETURNS : int - 1 if it's a text file 0 if it's a binary
*/
int is_binary(const void *data)
{
	return (my_str_isprintable((char *)data));
}

/*
** PURPOSE : Function that heuristically determines the type of a file from
**           it's content
** PARAMS  : char *name - Name of the file to test
** RETURNS : int - ascii based file : F_TEXT 1
**           (WIP)image based file : F_IMG 2
**           binary based file : F_BIN 3
*/
int get_file_type(char *name)
{
	char *buf;
	int len = 0;
	int ret = 0;
	FILE *filep = fopen(name, "r");

	if (!filep)
		return (F_ERROR);
	do {
		buf = smalloc(sizeof(char) * (LEN_TO_READ + 1));
		len = fread(buf, 1, LEN_TO_READ, filep);
		buf[len] = '\0';
		if (!is_binary(buf)) {
			free(buf);
			ret = F_BIN;
			break;
		}
		free(buf);
	} while (len == LEN_TO_READ);
	fclose(filep);
	return (ret == 0 ? F_TEXT : ret);
}
