/*
** EPITECH PROJECT, 2017
** my_swap
** File description:
** thomas.foubert@epitech.eu
*/

/*
** PURPOSE : Function that swaps the values of 2 int pointers
** PARAMS  : int *a
**           int *b
** RETURNS : None
*/
void my_swap_int(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
