/*
** EPITECH PROJECT, 2017
** middle_print.c by tfoubert <thomas.foubert@epitech.eu>
** File description:
** middle_print.c file of the {{project_name}} project
*/

#include "libC.h"
#include "explorer.h"

/*
** PURPOSE : Function used to print something in the middle of a window
** PARAMS  : WINDOW *win - Window used
**           int *start - Coordinate values :
**                        0 : x
**                        1 : y
**                        2 : width
**           char *string - String to write
**           chtype color - Color used to write
** RETURNS : None
*/
void print_in_middle(WINDOW *win, int *start, char *string, chtype color)
{
	int length;
	int x;
	int y;
	float temp;

	getyx(win, y, x);
	if(start[0] != 0)
		x = start[0];
	if(start[1] != 0)
		y = start[1];
	if(start[2] == 0)
		start[2] = 80;
	length = strlen(string);
	temp = (start[2] - length)/ 2;
	x = start[0] + (int)temp;
	wattron(win, color);
	mvwprintw(win, y, x, "%s", string);
	wattroff(win, color);
	refresh();
}
