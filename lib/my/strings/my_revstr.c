/*
** EPITECH PROJECT, 2017
** my_revstr
** File description:
** a function that reverse a string
*/

char *my_strdup(char const *src);
int my_strlen(char const *str);

char *my_revstr(char *str)
{
	int i = my_strlen(str) - 1;
	int j = 0;
	char x;
	char *temp = my_strdup(str);

	while (i >= j) {
		x = temp[j];
		temp[j] = temp[i];
		temp[i] = x;
		i--;
		j++;
	}
	return (temp);
}
