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
#include "memory.h"
#include "strings.h"

/*
** PURPOSE : Function used by qsort to sort an array
** PARAMS  : const void *a - Char to be tested
**           const void *b - Char to be tested
** RETURNS : int - Return the return of strcmp
*/
static int compare_str(const void *a, const void *b)
{
	char *adup = strdup(*(char **)a);
	char *bdup = strdup(*(char **)b);
	int ret = 0;

	my_strlowcase(adup);
	my_strlowcase(bdup);
	ret = strcmp(adup, bdup);
	free(adup);
	free(bdup);
	return (ret);
}

/*
** PURPOSE : Walk non-recursively a given dir and put the files and dir paths
**           into a list
** PARAMS  : const char *dir - The directory to walk
**           const char *pattern - Regex pattern to match
**           int *i - Number of files counter
** RETURNS : char ** - The files list, NULL if error
*/
char **walk_dir(char *dir, regex_t *reg, int *i)
{
	DIR *d;
	char **temp;
	struct dirent *entry;
	char **list = (char **)smalloc(sizeof(char *));

	if (!(d = opendir(dir))) {
		perror("opendir");
		return (NULL);
	}
	while ((entry = readdir(d))) {
		if (!regexec(reg, entry->d_name, 0, NULL, 0)) {
			temp = (char**)realloc(list, (sizeof(char *) * (*i + 2)));
			list = temp != NULL ? temp : list;
			list[*i] = strdup(entry->d_name);
			list[*i + 1] = NULL;
			(*i)++;
		}
	}
	closedir(d);
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
	regex_t reg;
	char **list;

	if (regcomp(&reg, "^[^.].*$", REG_EXTENDED | REG_NOSUB)) {
		perror("regcomp");
		return (NULL);
	}
	if ((list = walk_dir(path, &reg, &i)) == NULL)
		exit(84);
	qsort(list, i, sizeof(char *), compare_str);
	regfree(&reg);
	return (list);
}
