/*
** EPITECH PROJECT, 2017
** my_str_isprintable
** File description:
** thomas.foubert@epitech.eu
*/

int my_str_isprintable(char *str)
{
	int i;
	int printable_count;

	if (str[0] == '\0')
		return (1);
	for (i = 0; str[i] != '\0'; i++) {
		if (str[i] <= 126 && str[i] >= 32)
			printable_count++;
		else
			return (0);
	}
	return (1);
}
