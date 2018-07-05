/*
** EPITECH PROJECT, 2017
** free_explorer.c by tfoubert <thomas.foubert@epitech.eu>
** File description:
** free_explorer.c file of the {{project_name}} project
*/

#include "libC.h"
#include "explorer.h"

/*
** PURPOSE : Free all explorer data
** PARAMS  : explorer_t *explorer - Explorer data
** RETURNS : None
*/
void free_explorer(explorer_t *explorer)
{
	free(explorer->cwd);
	free(explorer->file_io_name);
	free(explorer->file_io_path);
	free_all_nodes(explorer->head);
	free(explorer);
}
