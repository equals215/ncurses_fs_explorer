/*
** EPITECH PROJECT, 2017
** print_preview.c by tfoubert <thomas.foubert@epitech.eu>
** File description:
** print_preview.c file of the {{project_name}} project
*/

#include "libC.h"
#include "explorer.h"

/*
** PURPOSE : Print file contents with offset
** PARAMS  : WINDOW *prevw - Preview window
**           char *file - File to be previewed
**           int offset - File display offset (lines)
** RETURNS : None
*/
void print_file_with_offset(WINDOW *prevw, char *file, int offset)
{
	char *file_with_offset = strdup(file);

	for (int i = 0; i < offset; i++) {
		file_with_offset = strchr(file_with_offset, '\n');
		file_with_offset++;
	}
	mvwaddstr(prevw, 0, 0, file_with_offset);
}

/*
** PURPOSE : Function that print the preview of a file in the preview window
** PARAMS  : file_t *node - Node of the file to print
**           WINDOW *prevw - Window to print in
** RETURNS : None
*/
void print_preview(file_t *node, WINDOW *prevw, explorer_t *explorer)
{
	char *file;
	char *fallb = strdup("This cannot be previewed");
	int fallb_len = strlen(fallb);

	if (node->type == F_TEXT) {
		if ((file = get_file_content(node->name)) == NULL)
			mvwprintw(prevw, (PREVW_LINES - 2) / 2,
			((PREVW_COLS - 2) / 2) - (fallb_len / 2), fallb);
		else {
			print_file_with_offset(prevw, file,
			explorer->prevw_pos);
			free(file);
		}
	} else
		mvwprintw(prevw, (PREVW_LINES - 2) / 2,
		((PREVW_COLS - 2) / 2) - (fallb_len / 2), fallb);
	free(fallb);
}
