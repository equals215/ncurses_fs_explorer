/*
** EPITECH PROJECT, 2017
** str_isalpha
** File description:
** thomas.foubert@epitech.eu
*/

int my_str_isalpha(char *str)
{
	int i;
	char c;
	int alpha_count = 0;

	if (!str || str[0] == '\0')
		return (1);
	for (i = 0; str[i] != '\0'; i++){
		c = str[i];
		if ((c <= 90 && c >= 65) || (c <= 122 && c >= 97))
			alpha_count++;
		else
			return (0);
	}
	return (1);
}
