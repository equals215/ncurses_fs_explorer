/*
** EPITECH PROJECT, 2017
** my_strupcase
** File description:
** thomas.foubert@epitech.eu
*/

char *my_strupcase(char *str)
{
	int i = 0;

	for (; str[i] != '\0'; i++)
		if (str[i] <= 122 && str[i] >= 97)
			str[i] -= 32;
	return (str);
}
