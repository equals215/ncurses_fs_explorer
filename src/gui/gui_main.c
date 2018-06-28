/*
** EPITECH PROJECT, 2017
** gui_main.c by tfoubert <thomas.foubert@epitech.eu>
** File description:
** gui_main.c file of the {{project_name}} project
*/

#include "libC.h"
#include <ncurses.h>
#include "explorer.h"

void display_windows(void)
{
	WINDOW *main_w, *right_w;

	initscr();
	main_w = subwin(stdscr, LINES, COLS, 0, 0);
	right_w = subwin(stdscr, LINES - (LINES / 4), COLS / 3, 1, COLS - (COLS / 3) - 1);
	box(main_w, ACS_VLINE, ACS_HLINE);
	box(right_w, ACS_VLINE, ACS_HLINE);
	wborder(right_w, '/', '/', '/', '/', '/', '/', '/', '/');
	mvwprintw(main_w, 1, 1, "Ceci est la fenetre de navigation");
	mvwprintw(right_w, 1, 1, "Ceci est la fenetre de previsualisation");
	wrefresh(main_w);
	wrefresh(right_w);
}
