/*
** EPITECH PROJECT, 2017
** keyboard_ctrl_handler.c by tfoubert <thomas.foubert@epitech.eu>
** File description:
** keyboard_ctrl_handler.c file of the {{project_name}} project
*/

#include "libC.h"
#include "explorer.h"

/*
** PURPOSE : Truncate the filename at the end of a path
** PARAMS  : char *path - Path which will be truncated
** RETURNS : char* - Malloc'd string of the truncated path
*/
char *remove_filename(char *path)
{
	char *new_path = strdup(path);
	int i = strlen(new_path);

	for (; new_path[i] != '/' && i != 0; i--) {
		new_path[i] = '\0';
	}
	new_path[i] = '\0';
	return (new_path);
}

/*
** PURPOSE : Paste file and reload files
** PARAMS  : explorer_t *explorer - Explorer data
** RETURNS : int - State
*/
int paste(explorer_t *explorer)
{
	int state = 0;
	char *path_io = remove_filename(explorer->file_io_path);

	if (!strcmp(path_io, explorer->cwd))
		return (state);
	if (!(state = paste_file(explorer))) {
		free_all_nodes(explorer->head);
		explorer->head = NULL;
		get_files_and_dirs(explorer);
		explorer->tree_pos = 0;
	}
	return (state);
}

/*
** PURPOSE : Function used to interpret ctrl keyboard events
** PARAMS  : int ch - Key catched
**           explorer_t *explorer - Explorer data
** RETURNS : int - State
*/
int keyboard_ctrl_handling(int ch, explorer_t *explorer)
{
	switch (ch) {
		case 'c':
		case CTRL('c'):
			copy_cut_file(explorer, COPY);
			break;
		case 'x':
		case CTRL('x'):
			copy_cut_file(explorer, CUT);
			break;
		case 'v':
		case CTRL('v'):
			return (paste(explorer));
	}
	return (0);
}
