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
** PURPOSE : Create the first node of the list
** PARAMS  : char *name - name of the file to be added as a head
** RETURNS : file_t - The node
*/
file_t *create_head_node(char *name)
{
	file_t *actual = create_node(name);

	actual->prev = NULL;
	actual->next = NULL;
	actual->active = true;
	return (actual);
}

/*
** PURPOSE : Create a file_t node and put the files info inside
** PARAMS  : char *name - File name
** RETURNS : file_t - Fullfilled node
*/
file_t *create_node(char *name)
{
	file_t *new = smalloc(sizeof(file_t));
	struct stat fstat;

	new->name = strdup(name);
	new->active = 0;
	if (stat(name, &fstat) != 0) {
		perror("stat");
		return (NULL);
	}
	if ((fstat.st_mode & S_IFMT) == S_IFDIR) {
		new->dir = fstat.st_size != 0 ? true : false;
		new->type = F_DIR;
	} else if ((fstat.st_mode & S_IFMT) == S_IFREG && fstat.st_size != 0) {
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
	file_t *actual = create_head_node("..");
	char **list = parse_dir(explorer->cwd);

	head = actual;
	for (int i = 0; list[i] != NULL; i++) {
		actual->next = create_node(list[i]);
		if (list && actual->next != NULL && actual->next->type != F_ERROR) {
			actual->next->next = NULL;
			actual->next->prev = actual;
			actual = actual->next;
		} else if (actual->next != NULL)
			free_node(actual->next);
	}
	explorer->head = head;
	free_tab(list);
}
