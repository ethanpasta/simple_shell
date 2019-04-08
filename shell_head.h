#ifndef SHELL_HEAD
#define SHELL_HEAD
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct built
{
	char *built_in;
	void (*f)(char**);
} built_t;

int _strlen(char *);
int _strcmp(char *, char *);
int _puts(char *);
char **strtow(char *, char);
int word_count(char *, char);
char *find_path(char **);
char *check_file_withP(char **, char *);
char *str_concat(char *, char *);
int do_built_in(char *, char **, built_t *);
void print_env(char **);
void set_env(char **);
void unset_env(char **);
void change_dir(char **);
char **check_create_args(char **, size_t *);
void child_proc(char **, built_t *, char **, char **, size_t);
int _atoi(char *);
char *_itoa(size_t);
void error_msg(size_t, char **, char **);


#endif
