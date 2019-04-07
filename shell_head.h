#ifndef SHELL_HEAD
#define SHELL_HEAD

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
int do_built_in(char *arg, char** env, built_t a[]);
void print_env(char** env);
void set_env(char** env);
void unset_env(char** env);
void change_dir(char** env);

#endif
