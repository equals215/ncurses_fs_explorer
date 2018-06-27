/*
** EPITECH PROJECT, 2017
** strings.h by tfoubert <thomas.foubert@epitech.eu>
** File description:
** strings.h file of the libMy project
*/

#ifndef STRINGS_H
#define STRINGS_H

/* strings/my_strdup.c */
char *my_strdup(char const *);
/* strings/my_strcapitalize.c */
char uppercase(char *, int);
char *my_strcapitalize(char *);
/* strings/my_strlen.c */
int my_strlen(char const *);
/* strings/my_strncpy.c */
char *my_strncpy(char *, char const *, int);
/* strings/my_strncat.c */
char *my_strncat(char *, char const *, int);
/* strings/my_strcat.c */
char *my_strcat(char *, char const *);
/* strings/my_strlowcase.c */
char *my_strlowcase(char *);
/* strings/my_strstr.c */
int compare_string(char const *, char const *, int);
char *my_strstr(char *, char *);
/* strings/my_strncmp.c */
int my_strncmp(char const *, char const *, int);
/* strings/utils/my_str_isprintable.c */
int my_str_isprintable(char *);
/* strings/utils/my_str_isupper.c */
int my_str_isupper(char *);
/* strings/utils/is_num.c */
int is_num(char);
/* strings/utils/my_str_islower.c */
int my_str_islower(char *);
/* strings/utils/my_str_isalpha.c */
int my_str_isalpha(char *);
/* strings/utils/my_str_isnum.c */
int my_str_isnum(char *);
/* strings/utils/is_alpha.c */
int is_alpha(char);
/* strings/my_strcmp.c */
int my_strcmp(char const *, char const *);
/* strings/my_strupcase.c */
char *my_strupcase(char *);
/* strings/my_strtod.c */
char *my_strtod(char *, char *, char **);
/* strings/my_strcpy.c */
char *my_strcpy(char *, char const *);
/* strings/my_revstr.c */
char *my_revstr(char *);

#endif
