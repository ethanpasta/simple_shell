#ifndef SHELL_HEAD
#define SHELL_HEAD
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* Struct definition for built ins */
typedef struct built
{
	char *built_in;
	void (*f)(char**);
} built_t;

/* Functions in string_f.c */
int _strlen(char *);
int _strcmp(char *, char *);
int _puts(char *, int);
char **strtow(char *, char);

/* Functions in string_split.c */
int word_count(char *, char);
char *str_concat(char *, char *);

/* Functions in handle_path.c */
char *find_env_value(char **, char *);
char *check_file_withP(char **, char *);

/* Functions in built_f.c */
int do_built_in(char *, char **, built_t *);
void print_env(char **);
void set_env(char **, char *, char *);
void unset_env(char **);
void change_dir(char **);

/* Functions in help_main.c */
char **check_create_args(char **, size_t *);
void child_proc(char **, built_t *, char **, char **, size_t);
void error_msg(size_t, char **, char **);

/* Functions in int_string.c */
int _atoi(char *);
char *_itoa(size_t);

#endif
