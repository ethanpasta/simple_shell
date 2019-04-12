# simple_shell
## Description
Write a simple UNIX command interpreter. For this project we are creating our own simple shell using the C programming language. 
### Prototype
`int main(int ac, char **av, char **env)`
### Example Usage
* `:) ls -l` - lists all files in your current directory in long format and then prints the prompt on the new line.
* `:) \bin\ls` - lists all file in your current directory and then prints the prompt on the new line.
* `:) env` - prints a list of the current environment variables.
* `:) exit` - exits out of the shell followed by a new line.
### Files
File Name | Description
--- | ---
[AUTHORS](https://github.com/ethanpasta/simple_shell/blob/master/AUTHORS) | This file store the contact info of all individuals who contributed to the branches of our shell code, 
[builtin_f.c](https://github.com/ethanpasta/simple_shell/blob/master/builtin_f.c) | This file is where we stord all the code we wrote for our built-in commands. It contains the code for the functions `print_env`, `exit`, `setenv` and `unsetenv`. As well as the `do_built_in` function that goes through our array of functions o search for the correct built-ins.
[handle_path.c](https://github.com/ethanpasta/simple_shell/blob/master/handle_path.c) | Contains 2 functions that handle the PATH environmental variable. The `find_env_value` function returns the PATH in the env, while the `check_file_withP` function will check if the command exist inside the PATH directories.
[help_main.c](https://github.com/ethanpasta/simple_shell/blob/master/help_main.c) | All the functions we used in pur `main.c` file is inside this file. 
[int_string.c](https://github.com/ethanpasta/simple_shell/blob/master/int_string.c) | Where we placed our `_atoi` and `_itoa` functions.
[main.c](https://github.com/ethanpasta/simple_shell/blob/master/main.c) | Our entry point for the simple shell. This where the main stroke of our shell will start from.
[man_1_simple_shell](https://github.com/ethanpasta/simple_shell/blob/master/man_1_simple_shell) | The man page for our simple shell. Type in `man ./man_1_simple_shell` to see the man page on your editor.
[realloc.c](https://github.com/ethanpasta/simple_shell/blob/master/realloc.c) | The file where the `_realloc` function is written.
[shell_head.h](https://github.com/ethanpasta/simple_shell/blob/master/shell_head.h) | Our header file that contains all the libraies we used and all our prototypes we created. As well as the 2 structs we created.
[string_f.c](https://github.com/ethanpasta/simple_shell/blob/master/string_f.c) | This where all our custom built string functions are stored. i.e `_strlen`, `_puts`
[string_split.c](https://github.com/ethanpasta/simple_shell/blob/master/string_split.c) | Where we created our custom built strtok function we name `strtow`.
### Compilation
Our shell can be compiled either this way:
`gcc -Wall -Werror -Wextra -pedantic *.c -o hsh`
Or this way:
`gcc *.c -o hsh`
### Bugs
### Authors
- **Ethan Mayer** - [ethanpasta](https://github.com/ethanpasta/simple_shell)
- **Jun Zhu** - [VieetBubbles](https://github.com/VieetBubbles)
### Acknowledgments
- **Tu Vu**
- **Jason Cortella**
- **Laura Roudge**
- **Arthur Damm**
