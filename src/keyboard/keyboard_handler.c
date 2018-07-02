/*
** EPITECH PROJECT, 2017
** keyboard_handler.c by tfoubert <thomas.foubert@epitech.eu>
** File description:
** keyboard_handler.c file of the {{project_name}} project
*/

#include "libC.h"
#include "explorer.h"

/*
** PURPOSE : Make the next file an active file
** PARAMS  : explorer_t *explorer - Explorer data
** RETURNS : None
*/
void next_file(explorer_t *explorer)
{
	file_t *actual = explorer->head;

	while (actual->active == false && actual->next != NULL)
		actual = actual->next;
	if (actual->active == true && actual->next != NULL) {
		actual->active = false;
		actual->next->active = true;
	} else
		return;
}

/*
** PURPOSE : Make the previous file an active file
** PARAMS  : explorer_t *explorer - Explorer data
** RETURNS : None
*/
void prev_file(explorer_t *explorer)
{
	file_t *actual = explorer->head;

	while (actual->active == false && actual->next != NULL)
		actual = actual->next;
	if (actual->active == true && actual->prev != NULL) {
		actual->active = false;
		actual->prev->active = true;
	} else
		return;
}

/*
** PURPOSE : Function used to catch and interpret keyboard events
** PARAMS  : explorer_t *explorer - Explorer data
** RETURNS : int - Action to do
*/
int keyboard_event(explorer_t *explorer)
{
	int ch;

	display_too_small();
	ch = getch();
	switch (ch) {
		case 'q':
			return (1);
		case KEY_UP:
			prev_file(explorer);
			break;
		case KEY_DOWN:
			next_file(explorer);
			break;
		default:
			break;
	}
	return (0);
}
