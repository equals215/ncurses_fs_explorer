/*
** EPITECH PROJECT, 2017
** funcs.h by tfoubert <thomas.foubert@epitech.eu>
** File description:
** funcs.h file of the {{project_name}} project
*/

/* src/core/tree/file_parsing.c */
int is_binary(const void *);
int get_file_type(char *);
/* src/core/tree/list_parsing.c */
file_t *create_head_node(char *);
file_t *create_node(char *);
void get_files_and_dirs(explorer_t *);
/* src/core/tree/dir_parsing.c */
char **walk_dir(char *, regex_t *, int *);
char **parse_dir(char *);
/* src/core/utils/getpwd.c */
char *getpwd(void);
/* src/core/utils/init_explorer.c */
explorer_t *init_explorer(int, char **);
/* src/core/utils/free_tab.c */
void free_tab(char **);
/* src/core/utils/free_nodes.c */
void free_all_nodes(file_t *);
void free_node(file_t *);
/* src/core/utils/free_explorer.c */
void free_explorer(explorer_t *);
/* src/gui/color_handler.c */
void enable_color(WINDOW *, file_t *);
void disable_color(WINDOW *, file_t *);
/* src/gui/utils/middle_print.c */
void print_in_middle(WINDOW *, int *, char *, chtype);
/* src/gui/utils/init_gui.c */
void init_gui(void);
/* src/gui/gui_main.c */
void display_too_small(void);
void display_files(WINDOW *, explorer_t *);
void display_windows(WINDOW **, WINDOW **, explorer_t *);
/* src/main.c */
int main(int, char **);
/* src/keyboard/keyboard_handler.c */
void next_file(explorer_t *);
void prev_file(explorer_t *);
void change_dir(explorer_t *);
int keyboard_event(explorer_t *);
