/*
** EPITECH PROJECT, 2017
** my_print_isneg
** File description:
** task04
*/

void my_putchar(char c);

/*
** PURPOSE : Function that returns 1 if the given int is negative
** PARAMS  : int n - The number to test
** RETURNS : int - 1 or 0
*/
int my_isneg(int n)
{
	if (n >= 0)
		return (0);
	return (1);
}
