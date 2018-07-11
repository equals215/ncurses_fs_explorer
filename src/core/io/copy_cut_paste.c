/*
** EPITECH PROJECT, 2017
** copy_cut_paste.c by tfoubert <thomas.foubert@epitech.eu>
** File description:
** copy_cut_paste.c file of the {{project_name}} project
*/

#include "libC.h"
#include "explorer.h"
#include "memory.h"

/*
** PURPOSE : Paste a previously copied file
** PARAMS  : explorer_t *explorer - Explorer data
** RETURNS : None
*/
void paste_file(explorer_t *explorer)
{
	int child_exit;
	pid_t pid;
	pid_t ws;

	if ((pid = fork()) == 0) {
		execl("/bin/cp", "cp", explorer->file_io_path,
		explorer->cwd, (char *) NULL);
	} else if (pid < 0) {
		fprintf(stderr, "explorer: Couldn't fork\n");
		end_gui(explorer, 84);
	} else {
		ws = waitpid(pid, &child_exit, WNOHANG);
		if (ws == -1) {
			fprintf(stderr, "explorer: Something %s\n",
			"unexpected happend");
			end_gui(explorer, 84);
		} else if (ws != -1 && explorer->io_action == CUT)
			remove(explorer->file_io_path);
	}
}

/*
** PURPOSE : Copy a file
** PARAMS  : explorer_t *explorer - Explorer data
**           int action - Action to perform
** RETURNS : None
*/
void copy_cut_file(explorer_t *explorer, int action)
{
	file_t *actual = explorer->head;
	char *buf = smalloc(sizeof(char) * PATH_MAX);

	while (actual->active == false && actual->next != NULL)
		actual = actual->next;
	explorer->io_action = action;
	explorer->file_io_path = realpath(actual->name, buf);
}
