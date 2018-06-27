/*
** EPITECH PROJECT, 2017
** get_next_line.h
** File description:
** get_next_line.h file of the CPE_getnextline_2017 project
*/

#include <unistd.h>
#include <stdlib.h>
#include "parsing.h"
#include "memory.h"
#include "strings.h"

static char *append(int *i_buff, int i_line, char *line, char *buff)
{
	int init_len = line ? my_strlen(line) : 0;
	char *ret = (char *)malloc(sizeof(*ret) * (init_len + i_line + 1));

	if (ret == NULL) {
		free(ret);
		return (NULL);
	}
	my_strncpy(ret, line ? line : "", init_len);
	my_strncpy(ret + init_len, buff + *i_buff, i_line);
	free(line);
	*i_buff += i_line + 1;
	return (ret);
}

char *get_next_line(int fd)
{
	char *line = NULL;
	static int read_value = 0;
	static int i_buff = 0;
	static char buff[READ_SIZE];

	for (int i_line = 0; 1; i_line++) {
		if (read_value <= i_buff &&
			!(read_value = read(fd, buff, READ_SIZE)))
			return (line);
		else if (read_value <= i_buff && read_value == -1)
			return (NULL);
		if (read_value <= i_buff) {
			i_line = 0;
			i_buff = 0;
		}
		if (buff[i_buff + i_line] == '\n')
			return (append(&i_buff, i_line, line, buff));
		if (i_buff + i_line == read_value - 1)
			line = append(&i_buff, i_line + 1, line, buff);
	}
}
