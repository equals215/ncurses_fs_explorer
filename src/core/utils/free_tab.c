/*
** EPITECH PROJECT, 2017
** free_tab.c by tfoubert <thomas.foubert@epitech.eu>
** File description:
** free_tab.c file of the {{project_name}} project
*/

#include "libC.h"

/*
** PURPOSE : Free entirely the given NULL terminated tab
** PARAMS  : char **tab - tab to free
** RETURNS : None
*/
void free_tab(char **tab)
{
	for (int i = 0; tab[i] != NULL; i++)
		free(tab[i]);
	free(tab);
}
