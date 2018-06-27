/*
** EPITECH PROJECT, 2017
** my_strstr
** File description:
** thomas.foubert@ymail.com
*/
#include <string.h>

int my_strlen(char const *);

int compare_string(char const *str, char const *find, int itstr)
{
	int itfind = 0;

	while (find[itfind] != '\0') {
		if (str[itstr] == find[itfind] && itfind == my_strlen(find) - 1)
			return (1);
		if (str[itstr] != find[itfind])
			return (0);
		if (str[itstr] == find[itfind]) {
			itstr += 1;
			itfind += 1;
		}
	}
	return (0);
}

char *my_strstr(char *str, char *to_find)
{
	int itstr = 0;
	int status = 0;

	while (str[itstr] != '\0') {
		if (str[itstr] == to_find[0])
			status = compare_string(str, to_find, itstr);
		if (status == 1)
			return (&str[itstr]);
		if (itstr == my_strlen(str) - 1)
			return (NULL);
		if (status == 0)
			itstr += 1;
	}
	return (0);
}
