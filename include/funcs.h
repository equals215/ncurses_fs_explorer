/*
** EPITECH PROJECT, 2017
** funcs.h by tfoubert <thomas.foubert@epitech.eu>
** File description:
** funcs.h file of the {{project_name}} project
*/

/* src/core/tree/dir_parsing.c */
int list(const char *, const struct stat *, int, struct FTW *);
void epur_path(char *, char *);
char **put_in_array(char *, int *);
char **parse_dir(char *);
/* src/core/utils/getpwd.c */
char *getpwd(void);
/* src/core/utils/is_binary.c */
int is_binary(const void *, size_t);
/* src/gui/gui_main.c */
void display_windows(WINDOW **, WINDOW **);
/* src/main.c */
int main(int, char **);
/* src/keyboard/keyboard_handler.c */
int keyboard_event(void);
