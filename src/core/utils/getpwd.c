/*
** EPITECH PROJECT, 2017
** getpwd.c by tfoubert <thomas.foubert@epitech.eu>
** File description:
** getpwd.c file of the {{project_name}} project
*/

#include "libC.h"
#include "memory.h"
#include <linux/limits.h>

char *getpwd(void)
{
	char *ret;
	char *buf = (char *)smalloc(PATH_MAX);

	memset(buf, '\0', 1000);
	ret = getcwd(buf, 1000);
	free(buf);
	return (ret);
}
