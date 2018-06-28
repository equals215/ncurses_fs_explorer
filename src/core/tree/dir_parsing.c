/*
** EPITECH PROJECT, 2017
** dir_parsing.c by tfoubert <thomas.foubert@epitech.eu>
** File description:
** dir_parsing.c file of the {{project_name}} project
*/

#include "libC.h"
#include "parsing.h"
#include <ncurses.h>
#include "explorer.h"

/*
** PURPOSE : Function used by qsort to sort an array
** PARAMS  : const void *a - Char to be tested
**           const void *b - Char to be tested
** RETURNS : int - Return the return of strcmp
*/
static int compare_str(const void *a, const void *b)
{
	return (strcmp(*(char **)a, *(char **)b));
}

/*
** PURPOSE : Function used by nftw that prints the entire path in a temp file
** PARAMS  : const char *name - Name of the dir to be parsed
**           const struct stat *status - Non-used but mandatory arg
**           int type - Type of the dir given by nftw
**           struct FTW *ftwbuf - Special nftw function that gives some info
** RETURNS : int - Returns -1 on incident
*/
int list(const char *name, const struct stat *status, int type,
struct FTW *ftwbuf)
{
	FILE *temp = fopen("temp", "a");

	(void)status;
	if (type == FTW_NS || type == FTW_DNR)
		return (-1);
	if (type == FTW_F && !(strstr(name, "/.") != NULL
	&& ftwbuf->level >= 1))
		fprintf(temp, "%s\n", name);
	if (type == FTW_D && name[0] != '.')
		fprintf(temp, "%s/\n", name);
	fclose(temp);
	return (0);
}

/*
** PURPOSE : Epur file name from complex path
** PARAMS  : char *name - name to epur
**           char *path - original path to epur from name
** RETURNS : None
*/
void epur_path(char *name, char *path)
{
	int nb_slash = 0;
	int len_path = strlen(path);
	int len_last_dir = 0;
	int total = 0;
	char *temp;

	for (int i = 0; path[i] != '\0'; i++)
		nb_slash += path[i] == '/' ? 1 : 0;
	if (nb_slash >= 1 && path[len_path - 1] == '/')
		path[--len_path] = '\0';
	else if (nb_slash >= 1) {
		temp = strrchr(path, '/');
		temp += 1;
		len_last_dir = strlen(temp);
		total = len_path - len_last_dir;
		memmove(name, name + total, strlen(name) - total + 1);
	}
}

/*
** PURPOSE : Parse the dir with nftw and put all the paths from temp file
**           and put them in array of strings
** PARAMS  : char *path - Path of the dir to parse
**           int *i - Counter that will be used later in the program
** RETURNS : char ** - The array of paths
*/
char **put_in_array(char *path, int *i)
{
	char *buf;
	char **temp;
	int ret = nftw(path, list, 1, FTW_PHYS);
	int fd = open("temp", O_RDONLY);
	char **list = (char **)malloc(sizeof(char *));

	if (ret == -1) {
		remove("temp");
		exit (84);
	} for (; (buf = get_next_line(fd)); (*i)++) {
		temp = (char**)realloc(list, (sizeof(char *) * (*i + 2)));
		list = temp ? temp : list;
		epur_path(buf, path);
		list[*i] = strdup(buf);
		list[*i + 1] = NULL;
		free(buf);
	}
	close(fd);
	remove("temp");
	return (list);
}

/*
** PURPOSE : Main function for parsing and printing the dir
** PARAMS  : char *path - Path of the dir
**           int mode - PRINT or NO_PRINT
** RETURNS : char ** - Return parsed array of paths
*/
char **parse_dir(char *path)
{
	int i = 0;
	char **list;

	list = put_in_array(path, &i);
	qsort(list, i, sizeof(const char *), compare_str);
	return (list);
}
