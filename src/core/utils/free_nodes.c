/*
** EPITECH PROJECT, 2017
** free_node.c by tfoubert <thomas.foubert@epitech.eu>
** File description:
** free_node.c file of the {{project_name}} project
*/

#include "libC.h"
#include "explorer.h"

/*
** PURPOSE : Free all nodes of the linked list
** PARAMS  : file_t *head - Head of the linked list
** RETURNS : None
*/
void free_all_nodes(file_t *head)
{
	file_t *temp;
	file_t *actual = head;

	while (actual != NULL) {
		temp = actual;
		actual = actual->next;
		free_node(temp);
	}
}

/*
** PURPOSE : Free a file node
** PARAMS  : file_t *node - node to free
** RETURNS : None
*/
void free_node(file_t *node)
{
	free(node->name);
	free(node);
}
