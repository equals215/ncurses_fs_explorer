/*
** EPITECH PROJECT, 2017
** my_strlen
** File description:
** thomas.foubert@epitech.eu
*/

int my_strlen(char const *str)
{
	int i = 0;

	for (; str[i] != '\0'; i++);
	return (i);
}
