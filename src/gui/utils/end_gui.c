/*
** EPITECH PROJECT, 2017
** end_gui.c by tfoubert <thomas.foubert@epitech.eu>
** File description:
** end_gui.c file of the {{project_name}} project
*/

#include "libC.h"
#include "explorer.h"

/*
** PURPOSE : Function that terminate the gui and the program with an exit code
** PARAMS  : explorer_t *explorer - Explorer data
**           int exit_code - Exit code to use
** RETURNS : None
*/
void end_gui(explorer_t *explorer, int exit_code)
{
	clear();
	endwin();
	free_explorer(explorer);
	exit(exit_code);
}
