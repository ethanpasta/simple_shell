#ifndef SHELL_HEAD
#define SHELL_HEAD
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include <sys/wait.h>

/**
 * struct list_t - structure for nodes in a linked list
 * @str: string in node
 * @len: length of str
 * @next: pointer to next node in list
 */
typedef struct list_s
{
        char *str;
        unsigned int len;
        struct list_s *next;
} list_t;

/**
 * struct built_info_t - info structure for built-ins commands
 * @args: array of arguments
 * @env: linked list of environment variables
 * @env_s: string of environment variables
 */
typedef struct built_info
{
        char **args;
        list_t *env;
	char **env_s;
} built_info_t;

/**
 * struct build_t - structure for built ins and their functions
 * @built_in: built-in command string
 * @f: function pointer to each built-in function
 */
typedef struct built
{
        char *built_in;
	void (*f)(built_info_t *);
} built_t;

/* Functions in string_f.c */
int _strlen(char *);
int _strcmp(char *, char *);
int _puts(char *, int);
char **strtow(char *, char);
char *_strcpy(char *, char *);

/* Functions in string_f2.c */
char *_strdup(char *);
void _memcpy(char *, char *, unsigned int);

/* Functions in string_split.c */
int word_count(char *, char);
char *str_concat(char *, char *);

/* Functions in handle_path.c */
char *find_env_value(char **, char *);
char *check_file_withP(char **, char *);

/* Functions in built_f.c */
int do_built_in(built_t *, built_info_t *);
void print_env(built_info_t *);
void set_env(built_info_t *);
void unset_env(built_info_t *);
void change_dir(built_info_t *);
void exit_shell(built_info_t *);

/* Functions in help_main.c */
char **check_create_args(char **, size_t *);
void child_proc(built_t *, char **, size_t, pid_t *, built_info_t *);
void error_msg(size_t, char **, char **);
void free_array(char **);

/* Functions in int_string.c */
int _atoi(char *);
char *_itoa(size_t);

/* Functions in enviro.c */
list_t *copy_env(char **);
char **list_to_array(list_t *);

/* Functions in list_f.c */
int add_node(list_t **, char *);
void free_list(list_t *);
size_t list_len(list_t *);
void print_list(list_t *);

/* Functions in list_f2.c */
int remove_node(list_t **, char *);

/* Functions in modify_env.c */
void help_setenv(list_t **, char *, char *);
void help_unsetenv(list_t **, char *);

/* Functions in built_f2.c */
void change_dir(built_info_t *);

#endif
