/*
** EPITECH PROJECT, 2017
** main.c by tfoubert <thomas.foubert@epitech.eu>
** File description:
** main.c file of the {{project_name}} project
*/

#include "libC.h"
#include <ncurses.h>
#include "explorer.h"

int main(void)
{
	initscr();
	printw("Hello World");
	refresh();
	getch();
	endwin();
	return ( 0);
}
