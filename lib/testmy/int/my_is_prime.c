/*
** EPITECH PROJECT, 2017
** my_is_prime
** File description:
** thomas.foubert@epitech.eu
*/

int my_is_prime(int nb)
{
	int i = 2;

	while (i <= nb / 2) {
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}
