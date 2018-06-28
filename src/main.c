/*
** EPITECH PROJECT, 2017
** main.c by tfoubert <thomas.foubert@epitech.eu>
** File description:
** main.c file of the {{project_name}} project
*/

#include "libC.h"
#include <ncurses.h>
#include "explorer.h"

int main(int ac, char **av)
{
	WINDOW *main_w;
	WINDOW *right_w;
	char **dir;

	(void)ac;
	(void)av;
	initscr();
	while (1) {
		dir = parse_dir(getpwd());
		display_windows(&main_w, &right_w);
		wrefresh(main_w);
		wrefresh(right_w);
		if(keyboard_event() == 1)
			break;
		clear();
	}
	endwin();
	return (0);
}
