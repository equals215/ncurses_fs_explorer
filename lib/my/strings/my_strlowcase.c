/*
** EPITECH PROJECT, 2017
** my_strlowcase
** File description:
** thomas.foubert@epitech.eu
*/

char *my_strlowcase(char *str)
{
	int i = 0;

	for (; str[i] != '\0'; i++)
		if (str[i] <= 90 && str[i] >= 65)
			str[i] += 32;
	return (str);
}
