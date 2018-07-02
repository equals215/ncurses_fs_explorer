/*
** EPITECH PROJECT, 2017
** getpwd.c by tfoubert <thomas.foubert@epitech.eu>
** File description:
** getpwd.c file of the {{project_name}} project
*/

#include "libC.h"
#include "memory.h"
#include <linux/limits.h>

/*
** PURPOSE : Get the current working dir
** PARAMS  : None
** RETURNS : char - The current working dir in a malloc'd string
*/
char *getpwd(void)
{
	char *ret;
	char *buf = (char *)smalloc(PATH_MAX);

	memset(buf, '\0', 1000);
	ret = strdup(getcwd(buf, 1000));
	free(buf);
	return (ret);
}
