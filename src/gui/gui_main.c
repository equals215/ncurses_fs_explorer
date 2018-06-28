/*
** EPITECH PROJECT, 2017
** gui_main.c by tfoubert <thomas.foubert@epitech.eu>
** File description:
** gui_main.c file of the {{project_name}} project
*/

#include "libC.h"
#include <ncurses.h>
#include "explorer.h"

/*
** PURPOSE : Display UI windows
** PARAMS  : WINDOW **main_w - Main window pointer
**           WINDOW **right_w - Right window pointer
** RETURNS : None
*/
void display_windows(WINDOW **main_w, WINDOW **right_w)
{
	*main_w = subwin(stdscr, LINES, COLS, 0, 0);
	*right_w = subwin(stdscr, LINES - (LINES / 4), COLS / 3, 1,
	COLS - (COLS / 3) - 1);
	box(*main_w, ACS_VLINE, ACS_HLINE);
	box(*right_w, ACS_VLINE, ACS_HLINE);
	wborder(*right_w, '/', '/', '/', '/', '/', '/', '/', '/');
}
