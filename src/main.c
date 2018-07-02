/*
** EPITECH PROJECT, 2017
** main.c by tfoubert <thomas.foubert@epitech.eu>
** File description:
** main.c file of the {{project_name}} project
*/

#include "libC.h"
#include "explorer.h"
#include "memory.h"

int main(int ac, char **av)
{
	WINDOW *main_w;
	WINDOW *right_w;
	explorer_t *explorer = init_explorer(ac, av);

	initscr();
	while (1) {
		get_files_and_dirs(explorer);
		display_windows(&main_w, &right_w);
		//display_files();
		wrefresh(main_w);
		wrefresh(right_w);
		if(keyboard_event() == 1)
			break;
		clear();
	}
	endwin();
	return (0);
}
