/*
** EPITECH PROJECT, 2017
** list_parsing.c by tfoubert <thomas.foubert@epitech.eu>
** File description:
** list_parsing.c file of the {{project_name}} project
*/

#include "libC.h"
#include "explorer.h"
#include "memory.h"

/*
** PURPOSE : Create a file_t node and put the files info inside
** PARAMS  : char *name - File name
**           int i -File index in the dir
** RETURNS : file_t - Fullfilled node
*/
file_t *create_node(char *name, int i)
{
	file_t *new = smalloc(sizeof(file_t));
	struct stat filestat;

	new->name = strdup(name);
	new->active = i == 0 ? true : false;
	if (stat(name, &filestat) != 0) {
		perror("stat");
		return (NULL);
	}
	if ((filestat.st_mode & S_IFMT) == S_IFDIR) {
		new->dir = true;
		new->type = F_DIR;
	} else if ((filestat.st_mode & S_IFMT) == S_IFREG) {
		new->dir = false;
		new->type = get_file_type(name, 100);
	} else {
		new->dir = false;
		new->type = F_OTHER;
	}
	return (new);
}

/*
** PURPOSE : Parse files and dirs list into the linked list
** PARAMS  : explorer_t *explorer - The explorer data
** RETURNS : None
*/
void get_files_and_dirs(explorer_t *explorer)
{
	file_t *head;
	file_t *actual = explorer->head;
	char **list = parse_dir(explorer->cwd);

	for (int i = 0; list[i] != NULL; i++) {
		if (actual == NULL) {
			actual = create_node(list[i], i);
			actual->prev = NULL;
			actual->next = NULL;
			head = actual;
		} else {
			actual->next = create_node(list[i], i);
			actual->next->next = NULL;
			actual->next->prev = actual;
			actual = actual->next;
		}
	}
	explorer->head = head;
	free_tab(list);
}
