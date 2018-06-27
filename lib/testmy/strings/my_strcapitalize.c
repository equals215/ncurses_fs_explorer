/*
** EPITECH PROJECT, 2017
** my_strcapitalize
** File description:
** thomas.foubert@epitech.eu
*/

char uppercase(char *str, int i)
{
	if (str[i] <= 122 && str[i] >= 97)
		return (str[i] - 32);
	else
		return (str[i]);
}

char *my_strcapitalize(char *str)
{
	int i = 1;

	for (; str[i] != '\0'; i++) {
		if (str[i - 1] == 32 || str[i - 1] == 42 || str[i - 1] == 45)
			str[i] = uppercase(str, i);
		else if (str[i] <= 90 && str[i] >= 65)
			str[i] += 32;
	}
	if (str[0] <= 122 && str[0] >= 97)
		str[0] -= 32;
	return (str);
}
