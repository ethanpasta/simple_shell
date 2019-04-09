#ifndef SHELL_HEAD
#define SHELL_HEAD
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>

/* Struct definition for built in arguments */
typedef struct built_info
{
	char **args;
	char **env;
} built_info_t;

/* Struct definition for built ins */
typedef struct built
{
	char *built_in;
	built_info_t *info;
	void (*f)(built_info_t *);
} built_t;

/* Functions in string_f.c */
int _strlen(char *);
int _strcmp(char *, char *);
int _puts(char *, int);
char **strtow(char *, char);
char *_strcpy(char *, char *);

/* Functions in string_split.c */
int word_count(char *, char);
char *str_concat(char *, char *);

/* Functions in handle_path.c */
char *find_env_value(char **, char *);
char *check_file_withP(char **, char *);

/* Functions in built_f.c */
int do_built_in(char **, char **, built_t[]);
void print_env(built_info_t *);
void set_env(built_info_t *);
void un_set_env(built_info_t *);
void change_dir(built_info_t *);
void exit_shell(built_info_t *);

/* Functions in help_main.c */
char **check_create_args(char **, size_t *);
void child_proc(char **, built_t *, char **, size_t, pid_t *);
void error_msg(size_t, char **, char **);

/* Functions in int_string.c */
int _atoi(char *);
char *_itoa(size_t);

/* Functions in realloc.c */
void *_realloc(void *, unsigned int, unsigned int);

#endif
