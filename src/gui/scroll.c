/*
** EPITECH PROJECT, 2017
** scroll.c by tfoubert <thomas.foubert@epitech.eu>
** File description:
** scroll.c file of the {{project_name}} project
*/

#include "libC.h"
#include "explorer.h"

void refresh_and_scroll(WINDOW *main, WINDOW *preview, explorer_t *explorer)
{
	prefresh(main, 0, 0, 0, 0, LINES, COLS);
}
