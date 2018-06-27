/*
** EPITECH PROJECT, 2017
** my_str_isupper
** File description:
** thomas.foubert@epitech.eu
*/

int my_str_isupper(char *str)
{
	int i;
	int upper_count;

	if (str[0] == '\0')
		return (1);
	for (i = 0; str[i] != '\0'; i++) {
		if (str[i] <= 90 && str[i] >= 65)
			upper_count++;
		else
			return (0);
	}
	return (1);
}
