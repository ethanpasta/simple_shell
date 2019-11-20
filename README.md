# simple_shell
A simple UNIX command interpreter.
## Description
This project was created as part of the third month curriculum at [Holberton School](https://www.holbertonschool.com/), San Francisco. In short, we we're required to write a UNIX command interpreter. Our shell replicates (to a certain degree) the `sh` shell. 

Due to it's simplicity, our custom-built shell has some of the functionalities of a normal shell, but not all of them. Down below we will describe each feature our shell contains.

### Compilation
To create an executable, compile the C files like this:
```
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh (or any other name you desire)
```
Or this way (without error checking):
```
gcc *.c -o hsh
```
### Entering the Shell
Once compiled, use the executable file `hsh` to enter. Your output for the shell should look something like this:
```
$ ./hsh
($hell) 
```

If the prompt (`$hell`) shows up and not the normal `$`, you'll know that you are in our custom shell.

### Example Usage
![Shell Example](images/shell-example.png)


### Exiting the Shell
To exit out of the shell, you can use either `CTRL + D`, or `CTRL + Z` or by typing in the built-in `exit` to the command line.

Do take note that the shell ignores the `CTRL + C` signal. When entered, the signal `^C` will be printed without exiting. To exit, use one of the inputs explained above. 

### Files
The following table describes in short the contents of each file in this repository.
File Name | Description
--- | ---
[builtin_f.c](https://github.com/ethanpasta/simple_shell/blob/master/builtin_f.c) | This file is where we stord all the code we wrote for our built-in commands. It contains the code for the functions `print_env`, `exit`, `setenv` and `unsetenv`. As well as the `do_built_in` function that goes through our array of functions o search for the correct built-ins.
[builtin_f2.c](https://github.com/ethanpasta/simple_shell/blob/master/builtin_f2.c) | File that contains more buit-in functions. Specifically, the `cd` builtin for change directory.
[handle_path.c](https://github.com/ethanpasta/simple_shell/blob/master/handle_path.c) | Contains 2 functions that handle the PATH environmental variable. The `find_env_value` function returns the PATH in the env, while the `check_file_withP` function will check if the command exist inside the PATH directories.
[help_main.c](https://github.com/ethanpasta/simple_shell/blob/master/help_main.c) | All the functions we used in pur `main.c` file is inside this file. 
[int_string.c](https://github.com/ethanpasta/simple_shell/blob/master/int_string.c) | Where we placed our `_atoi` and `_itoa` functions.
[list_array.c](https://github.com/ethanpasta/simple_shell/blob/master/list_array.c) | The file that contains our 2 functions to converts an array of strings into a linked list and vice versa converts linked list to an array of strings.
[list_f.c](https://github.com/ethanpasta/simple_shell/blob/B/list_f.c) | The file that contains the 1st half of all the functions concerning the topic of linked lists.
[list_f2.c](https://github.com/ethanpasta/simple_shell/blob/B/list_f2.c) | The file that contains the 2st half of all the functions concerning the topic of linked lists.
[main.c](https://github.com/ethanpasta/simple_shell/blob/master/main.c) | Our entry point for the simple shell. This where the main stroke of our shell will start from.
[man_1_simple_shell](https://github.com/ethanpasta/simple_shell/blob/master/man_1_simple_shell) | The man page for our simple shell. Type in `man ./man_1_simple_shell` to see the man page on your editor.
[modify_env.c](https://github.com/ethanpasta/simple_shell/blob/master/modify_env.c) | Contains 2 helper functions that are used for our `setenv` and `unsetenv` built-in functions.
[shell_head.h](https://github.com/ethanpasta/simple_shell/blob/master/shell_head.h) | Our header file that contains all the libraies we used and all our prototypes we created. As well as the 2 structs we created.
[string_f.c](https://github.com/ethanpasta/simple_shell/blob/master/string_f.c) | This where all our custom built string functions are stored. i.e `_strlen`, `_puts`
[string_f2.c](https://github.com/ethanpasta/simple_shell/blob/B/string_f2.c) | Another file that contains more functions that are related to strings.
[string_split.c](https://github.com/ethanpasta/simple_shell/blob/master/string_split.c) | Where we created our custom built strtok function we name `strtow`.
[var_replace.c](https://github.com/ethanpasta/simple_shell/blob/master/var_replace.c) | This is the file that contains the function that handles variable replacements. Mainly, used for the `echo $?` command.

### Output
Once compiling our program, you can see that our shell has the exact same output as well as the same error messages as `sh` does.
#### `sh`
```
$ echo "qwerty" | /bin/sh
/bin/sh: 1: qwerty: not found
$ echo "qwerty" | /bin/../bin/sh
/bin/../bin/sh: 1: qwerty: not found
$
```
* The error message is personalized to your exacutable filename, in this case `hsh`.
#### `./hsh` (our shell)
```
$ echo "qwerty" | ./hsh
./hsh: 1: qwerty: not found
$ echo "qwerty" | ./././hsh
./././hsh: 1: qwerty: not found
$
```
## Interactive vs Non-Interactive
Our shell can work in two different modes, interactive and non-interactive.

### Interactive Mode
The classic shell. Every time a command is entered, the prompt appears again and waits for more commands:
```
$ ./hsh
($) /bin/ls
AUTHORS handle_path.c  int_string.c  main.c
($)
($) exit
$
```

### Non-Interactive Mode
Piping a command into the executable file. Our shell executes the command, and exits the shell. 
```
$ echo "/bin/ls" | ./hsh
AUTHORS handle_path.c  int_string.c  main.c
$
$ echo "pwd" | ./hsh
/vagrant/home/
$
$ echo "ls -a" | ./hsh
AUTHORS handle_path.c  int_string.c  main.c .git . ..
$
```
### Built-in Commands
Our shell includes some of the built-in commands.

Each one of our custom built-in functions can be compared to the the `sh` shell output.
* **exit**
  * Usage - `$ exit` or `$ exit 98`
  * When entered correctly (a valid exit value), the user will exit the shell. If no value is entered, the shell will exit the return value of the last command entered.
  * You can see the exit value by entering `echo $?` after exiting the shell.

* **env**
  * Usage - `$ env`
  * When entered, all of the current environment variables will be printed.

* **setenv**
  * Usage - `$ setenv [VARIABLE] [VALUE]`
  * When entered, either a new environment variable is created, or an existing one is modified.
  * If an error occurs (e.g. no parameters included), a message is displayed to the standard error output.

* **unsetenv**
  * Usage - `$ unsetenv [VARIABLE]`
  * When entered, an environment variable is removed from the list.
  * If an error occurs (e.g. variable not found, no parameters included), a message is displayed to the standard error output.

* **cd**
  * Usage - `$ cd [DIRECTORY]`
  * When entered, the current working directory is changed.
  * `cd -`: changes the working directory the previous one.
  * `cd`: if no argument is entered, the command is interpreted as `cd $HOME`
  * If an error occurs (e.g. directory is not valid), a message is displayed to the standard error output.

### Variable Replacements
Our shell knows to replace variables with `$`.
  * `echo $PATH`: the variable `PATH` gets replaced with its value.
  * `echo $$`: the current process ID is displayed.
  * `echo $?`: the return/exit value of the last command entered is displayed.

### Bugs
A few memory leaks when entering commands that do not exist.

### About
All files were created and compiled on `Ubuntu 14.04.4 LTS` using `GCC 4.8.4`
### Authors
- **Ethan Mayer** - [ethanpasta](https://github.com/ethanpasta/simple_shell)
- **Jun Zhu** - [VieetBubbles](https://github.com/VieetBubbles)
### Acknowledgments
- **Tu Vu** - [tuvo1106](https://github.com/tuvo1106)
- **Jason Cortella** - [jasoncortella](https://github.com/jasoncortella)
- **Laura Roudge** - [lroudge](https://github.com/lroudge)
- **Arthur Damm** - [arthurdamm](https://github.com/arthurdamm)
