/*
** EPITECH PROJECT, 2017
** explorer.h by tfoubert <thomas.foubert@epitech.eu>
** File description:
** explorer.h file of the {{project_name}} project
*/

#ifndef EXPLORER_H
#define EXPLORER_H

typedef struct file_s
{
	bool active;
	bool dir;
	int type;
	char *name;
	struct file_s *next;
	struct file_s *prev;
}file_t;

typedef struct explorer_s
{
	file_t *head;
	char *cwd;
	int tree_pos;
	int prevw_pos;
}explorer_t;

#define F_TEXT 1
#define F_IMG 2
#define F_BIN 3
#define F_OTHER 4
#define F_DIR 5
#define F_ERROR 6

#define Y_MIN 80
#define X_MIN 20

#include <ncurses.h>

#define OFFSET(a, b) ((a) - ((b) - 3))
#define PREVW_LINES LINES - 2
#define PREVW_COLS COLS / 3

#define LEN_TO_READ 1024

#include "funcs.h"

#endif
