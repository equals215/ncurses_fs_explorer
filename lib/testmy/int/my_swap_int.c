/*
** EPITECH PROJECT, 2017
** my_swap
** File description:
** thomas.foubert@epitech.eu
*/

//Function that swaps the values of 2 int pointers
void my_swap_int(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
