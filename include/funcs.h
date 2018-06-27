/*
** EPITECH PROJECT, 2017
** funcs.h by tfoubert <thomas.foubert@epitech.eu>
** File description:
** funcs.h file of the {{project_name}} project
*/

/* src/printing/helper.c */
void print_helper(void);
/* src/printing/print_meeting.c */
int print_meet(char **, employee_t **, meeting_t **);
/* src/printing/print_employee.c */
void print_all_employees(employee_t *);
void print_empl_node(int, employee_t *, meeting_t *);
int print_empl(char **, employee_t **, meeting_t **);
/* src/execute/employee.c */
void dup_empl_values(char **, employee_t *);
int new_employee(char **, employee_t **, meeting_t **);
void delete_node(employee_t **, employee_t *);
int fire_empl(char **, employee_t **, meeting_t **);
/* src/execute/meeting.c */
int dup_values_new_meeting(char **, meeting_t *);
int new_meeting(char **, employee_t **, meeting_t **);
int invite_empl(char **, employee_t **, meeting_t **);
int exclude_empl(char **, employee_t **, meeting_t **);
int cancel_meet(char **, employee_t **, meeting_t **);
/* src/execute/commands.c */
int execute_command(char **, int, employee_t **, meeting_t **);
int end_command(char **, employee_t **, meeting_t **);
/* src/execute/infos.c */
int info_empl(char **, employee_t **, meeting_t **);
int info_meet(char **, employee_t **, meeting_t **);
/* src/error/check_date_format.c */
int check_date_part(char **, char **);
int check_date_format(char *);
/* src/utils/init_lists.c */
employee_t *init_empl(void);
meeting_t *init_meet(void);
/* src/utils/free_node.c */
void free_empl(employee_t *);
void free_meet(meeting_t *);
/* src/utils/strtab_len.c */
int my_strtab_len(char **);
/* src/utils/free_tab.c */
void free_tab(char **);
/* src/main.c */
int main(int, char **);
/* src/parsing/detect.c */
int detect_command(char **);
