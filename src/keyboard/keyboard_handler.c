/*
** EPITECH PROJECT, 2017
** keyboard_handler.c by tfoubert <thomas.foubert@epitech.eu>
** File description:
** keyboard_handler.c file of the {{project_name}} project
*/

#include "libC.h"
#include "explorer.h"

/*
** PURPOSE : Function used to catch and interpret keyboard events
** PARAMS  : None
** RETURNS : int - Action to do
*/
int keyboard_event(void)
{
	int ch;

	display_too_small();
	ch = getch();
	switch (ch) {
		case 'q':
			return (1);
		default:
			return (0);
	}
}
