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
** RETURNS : file_t - Fullfilled node
*/
file_t *create_node(char *name)
{
	file_t *new = smalloc(sizeof(file_t));
	struct stat filestat;

	new->name = strdup(name);
	new->active = 0;
	if (stat(name, &filestat) != 0) {
		perror("stat");
		return (NULL);
	}
	if ((filestat.st_mode & S_IFMT) == S_IFDIR) {
		new->dir = true;
		new->type = F_DIR;
	} else if ((filestat.st_mode & S_IFMT) == S_IFREG) {
		new->dir = false;
		new->type = get_file_type(name);
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

	actual = create_node("..");
	actual->prev = NULL;
	actual->next = NULL;
	actual->active = true;
	head = actual;
	for (int i = 0; list[i] != NULL; i++) {
		actual->next = create_node(list[i]);
		if (actual->next != NULL) {
			actual->next->next = NULL;
			actual->next->prev = actual;
			actual = actual->next;
		}
	}
	explorer->head = head;
	free_tab(list);
}
