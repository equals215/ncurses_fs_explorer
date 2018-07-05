/*
** EPITECH PROJECT, 2017
** file_parsing.c by tfoubert <thomas.foubert@epitech.eu>
** File description:
** file_parsing.c file of the {{project_name}} project
*/

#include "libC.h"
#include "explorer.h"

/*
** PURPOSE : Function used to get all the content of an ASCII file
** PARAMS  : char *name - Name of the file
** RETURNS : char - The content of the file in a buffer
*/
char *get_file_content(char *name)
{
	char *buf;
	size_t len = 0;
	FILE *filep = fopen(name, "r");

	if (filep != NULL) {
		getdelim(&buf, &len, '\0', filep);
		fclose(filep);
		return (buf);
	}
	return (NULL);
}
