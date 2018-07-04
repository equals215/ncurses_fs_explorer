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

	init_gui();
	get_files_and_dirs(explorer);
	while (1) {
		display_windows(&main_w, &right_w, explorer);
		display_files(main_w, explorer);
		wrefresh(main_w);
		wrefresh(right_w);
		display_too_small();
		if(keyboard_event(explorer) == 1)
			break;
		clear();
	}
	endwin();
	free_explorer(explorer);
	return (0);
}
