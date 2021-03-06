/*
** EPITECH PROJECT, 2017
** gui_main.c by tfoubert <thomas.foubert@epitech.eu>
** File description:
** gui_main.c file of the {{project_name}} project
*/

#include "libC.h"
#include "explorer.h"
#include "memory.h"

/*
** PURPOSE : Function used to prevent a too small terminal
** PARAMS  : None
** RETURNS : None
*/
void display_too_small(void)
{
	char *msg = "Screen too small.";
	int taille = strlen(msg);

	while (Y_MIN > COLS || X_MIN > LINES) {
		clear();
		mvprintw(LINES / 2, (COLS / 2) - (taille / 2), msg);
		refresh();
	}
}

/*
** PURPOSE : Display all files
** PARAMS  : WINDOW *win - Display window
**           explorer_t *explorer - Explorer data
** RETURNS : None
*/
void display_files(WINDOW *win, WINDOW* preview, explorer_t *explorer)
{
	file_t *actual = explorer->head;

	for (int count = 0; actual != NULL
	&& count < OFFSET(explorer->tree_pos, LINES); count++)
		actual = actual->next;
	for (int i = 0; actual != NULL && i < LINES - 2; i++) {
		if (actual->active == true) {
			print_preview(actual, preview);
			wattron(win, A_REVERSE);
		}
		enable_color(win, actual);
		mvwprintw(win, i + 1, 1, actual->name);
		wattroff(win, A_REVERSE);
		disable_color(win, actual);
		actual = actual->next;
	}
}

/*
** PURPOSE : Display UI windows
** PARAMS  : WINDOW **main_w - Main window pointer
**           WINDOW **right_w - Right window pointer
** RETURNS : None
*/
void display_windows(WINDOW **main_w, WINDOW **right_w, explorer_t *explorer)
{
	WINDOW *prevw;
	int coord[3];

	coord[0] = 1;
	coord[1] = 0;
	coord[2] = COLS;
	*main_w = subwin(stdscr, LINES, COLS, 0, 0);
	*right_w = subwin(stdscr, PREVW_LINES, PREVW_COLS, 1,
	COLS - (COLS / 3) - 1);
	prevw = derwin(*right_w, PREVW_LINES - 2, PREVW_COLS - 2, 1, 1);
	box(*main_w, ACS_VLINE, ACS_HLINE);
	box(*right_w, ACS_VLINE, ACS_HLINE);
	*right_w = prevw;
	print_in_middle(*main_w, coord, explorer->cwd, COLOR_WHITE);
}
