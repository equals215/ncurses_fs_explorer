/*
** EPITECH PROJECT, 2017
** print_preview.c by tfoubert <thomas.foubert@epitech.eu>
** File description:
** print_preview.c file of the {{project_name}} project
*/

#include "libC.h"
#include "explorer.h"

/*
** PURPOSE : Function that print the preview of a file in the preview window
** PARAMS  : file_t *node - Node of the file to print
**           WINDOW *prevw - Window to print in
** RETURNS : None
*/
void print_preview(file_t *node, WINDOW *prevw)
{
	char *file;
	char *fallb = strdup("This cannot be previewed");
	int fallb_len = strlen(fallb);

	if (node->type == F_TEXT) {
		if ((file = get_file_content(node->name)) == NULL)
			mvwprintw(prevw, (PREVW_LINES - 2) / 2,
			((PREVW_COLS - 2) / 2) - (fallb_len / 2), fallb);
		else {
			mvwprintw(prevw, 0, 0, file);
			free(file);
		}
	} else
		mvwprintw(prevw, (PREVW_LINES - 2) / 2,
		((PREVW_COLS - 2) / 2) - (fallb_len / 2), fallb);
	free(fallb);
}
