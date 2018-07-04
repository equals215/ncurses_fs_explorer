/*
** EPITECH PROJECT, 2017
** init_explorer.c by tfoubert <thomas.foubert@epitech.eu>
** File description:
** init_explorer.c file of the {{project_name}} project
*/

#include "libC.h"
#include "explorer.h"
#include "memory.h"

/*
** PURPOSE : Init the explorer data based on arguments
** PARAMS  : int ac - Number of arguments used to initiate the explorer
**           char **av - Arguments used to initiate the explorer
** RETURNS : explorer_t - The explorer_t structure initialized
*/
explorer_t *init_explorer(int ac, char **av)
{
	char *buf = smalloc(sizeof(char) * PATH_MAX);
	explorer_t *new = (explorer_t *)smalloc(sizeof(explorer_t));

	if (ac == 2 && opendir(av[1]) == NULL) {
		perror("explorer");
		exit(84);
	} else if (ac == 2) {
		new->cwd = realpath(av[1], buf);
		chdir(new->cwd);
	} else
		new->cwd = getpwd();
	new->head = NULL;
	new->pos = 0;
	return (new);
}
