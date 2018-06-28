/*
** EPITECH PROJECT, 2017
** keyboard_handler.c by tfoubert <thomas.foubert@epitech.eu>
** File description:
** keyboard_handler.c file of the {{project_name}} project
*/

#include "libC.h"
#include <ncurses.h>
#include "explorer.h"

int keyboard_event(void)
{
	int ch = getch();
	switch (ch) {
		case 'q':
			return (1);
		default:
			return (0);
	}
}
