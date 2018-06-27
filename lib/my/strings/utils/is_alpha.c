/*
** EPITECH PROJECT, 2017
** is_alpha.c by tfoubert <thomas.foubert@epitech.eu>
** File description:
** is_alpha.c file of the {{project_name}} project
*/

//Function that retuns 1 if the given char is alpha
int is_alpha(char c)
{
	if ((c <= 90 && c >= 65) || (c <= 122 && c >= 97))
		return (1);
	return (0);
}
