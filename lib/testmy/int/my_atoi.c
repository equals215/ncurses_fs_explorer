/*
** EPITECH PROJECT, 2017
** my_atoi.c
** File description:
** my_atoi.c
*/

//Function thats retuns the first digit/number contained in a string
int my_atoi(char *str)
{
	int nb = 0;
	int executed = 0;

	while (*str) {
		if (*str >= '0' && *str <= '9') {
			nb *= 10;
			nb += *str - '0';
			executed++;
		} else if (executed != 0)
			return (nb);

		str++;
	}
	return (nb);
}
