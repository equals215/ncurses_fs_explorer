/*
** EPITECH PROJECT, 2017
** keyboard_ctrl_handler.c by tfoubert <thomas.foubert@epitech.eu>
** File description:
** keyboard_ctrl_handler.c file of the {{project_name}} project
*/

#include "libC.h"
#include "explorer.h"

/*
** PURPOSE : Paste file and reload files
** PARAMS  : explorer_t *explorer - Explorer data
** RETURNS : None
*/
void paste(explorer_t *explorer)
{
	paste_file(explorer);
	free_all_nodes(explorer->head);
	explorer->head = NULL;
	get_files_and_dirs(explorer);
	explorer->tree_pos = 0;
}

/*
** PURPOSE : Function used to interpret ctrl keyboard events
** PARAMS  : int ch - Key catched
** RETURNS : None
*/
void keyboard_ctrl_handling(int ch, explorer_t *explorer)
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
			paste(explorer);
			break;
	}
}
