/*
** EPITECH PROJECT, 2017
** init_gui.c by tfoubert <thomas.foubert@epitech.eu>
** File description:
** init_gui.c file of the {{project_name}} project
*/

#include "libC.h"
#include "explorer.h"

void init_gui(void)
{
	initscr();
	curs_set(0);
	keypad(stdscr, TRUE);
	if (has_colors() == FALSE) {
		endwin();
		printf("Your terminal does not support color\n");
		exit(84);
	}
	start_color();
	init_pair(F_DIR, COLOR_BLUE, COLOR_BLACK);
	init_pair(F_BIN, COLOR_GREEN, COLOR_BLACK);
	init_pair(F_OTHER, COLOR_RED, COLOR_BLACK);
}
