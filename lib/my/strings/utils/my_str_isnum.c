/*
** EPITECH PROJECT, 2017
** my_str_isnum
** File description:
** thomas.foubert@epitech.eu
*/

/*
** PURPOSE : Checks if the given str is a number or not
** PARAMS  : char *str - Str to test
** RETURNS : int - 1 if true 0 if not
*/
int my_str_isnum(char *str)
{
	int i;
	int num_count;

	if (str[0] == '\0')
		return (0);
	for (i = 0; str[i] != '\0'; i++) {
		if (str[i] <= 57 && str[i] >= 49)
			num_count++;
		else
			return (1);
	}
	return (0);
}
