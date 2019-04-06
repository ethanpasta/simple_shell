#ifndef SHELL_HEAD
#define SHELL_HEAD

int _strlen(char *);
int _strcmp(char *, char *);
int _puts(char *);
char **strtow(char *, char);
int word_count(char *, char);
char *find_path(char **);
char *check_file_withP(char **, char *);
char *str_concat(char *, char *);

#endif
