/*
** EPITECH PROJECT, 2017
** my_strcmp
** File description:
** thomas.foubert@epitech.eu
*/

int my_strcmp(char const *s1, char const *s2)
{
	while ('\0' != *s1) {
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
