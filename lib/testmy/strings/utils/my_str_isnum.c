/*
** EPITECH PROJECT, 2017
** my_str_isnum
** File description:
** thomas.foubert@epitech.eu
*/

int my_str_isnum(char *str)
{
	int i;
	int num_count;

	if (str[0] == '\0')
		return (1);
	for (i = 0; str[i] != '\0'; i++) {
		if (str[i] <= 57 && str[i] >= 49)
			num_count++;
		else
			return (0);
	}
	return (1);
}
