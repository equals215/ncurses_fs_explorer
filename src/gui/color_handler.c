/*
** EPITECH PROJECT, 2017
** color_handler.c by tfoubert <thomas.foubert@epitech.eu>
** File description:
** color_handler.c file of the {{project_name}} project
*/

#include "libC.h"
#include "explorer.h"

/*
** PURPOSE : Enable colored writing based on the file type
** PARAMS  : WINDOW *win - Window
**           file_t *node - File node
** RETURNS : None
*/
void enable_color(WINDOW *win, file_t *node)
{
	switch (node->type) {
		case F_BIN:
			wattron(win, COLOR_PAIR(F_BIN));
			break;
		case F_DIR:
			wattron(win, COLOR_PAIR(F_DIR));
			break;
		case F_OTHER:
			wattron(win, COLOR_PAIR(F_OTHER));
			break;
		default:
			break;
	}
}

/*
** PURPOSE : Disable colored writing based on the file type
** PARAMS  : WINDOW *win - Window
**           file_t *node - File node
** RETURNS : None
*/
void disable_color(WINDOW *win, file_t *node)
{
	switch (node->type) {
		case F_BIN:
			wattroff(win, COLOR_PAIR(F_BIN));
			break;
		case F_DIR:
			wattroff(win, COLOR_PAIR(F_DIR));
			break;
		case F_OTHER:
			wattroff(win, COLOR_PAIR(F_OTHER));
			break;
		default:
			break;
	}
}
