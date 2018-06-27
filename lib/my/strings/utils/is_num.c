/*
** EPITECH PROJECT, 2017
** is_num.c by tfoubert <thomas.foubert@epitech.eu>
** File description:
** is_num.c file of the {{project_name}} project
*/

//Function that return 1 if the given char is a digit
int is_num(char c)
{
	if (c <= 57 && c >= 49)
		return (1);
	return (0);
}
