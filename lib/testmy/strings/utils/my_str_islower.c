/*
** EPITECH PROJECT, 2017
** my_str_islower
** File description:
** thomas.foubert@epitech.eu
*/

int my_str_islower(char *str)
{
	int i;
	int lower_count;

	if (str[0] == '\0')
		return (1);
	for (i = 0; str[i] != '\0'; i++) {
		if (str[i] <= 122 && str[i] >= 97)
			lower_count++;
		else
			return (0);
	}
	return (1);
}
