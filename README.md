# simple_shell
A very simple UNIX command interpreter.
## Description
Write a simple UNIX command interpreter. For this project we are creating our own simple shell using the C programming language. Our shell can read commands inputed into the command as files or standard input and executes them. In short, we created a sub-shell that your computer can run inside it's shell. A shell within a shell.

Due to it's simplicity, our custom-built shell does not 100% replicate the actual shell used on a computer. This project is a guide to how our custom shell works and what built-ins and commands it currently contains.

### Compilation
Our shell can be compiled either this way:
```
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```
Or this way:
```
gcc *.c -o hsh
```
### Entering the Shell
Once compiled, the executable file `./hsh` can be used to enter our custom shell. Your output for the shell should look something like this:
```
$ ./hsh
($)
```

Once the prompt (`$`) shows up and not the previous `$`, then you'll know that the custom-built shell is working.

### Example Usage
* `$ ls -l` - lists all files in your current directory in long format and then prints the prompt on the new line.
* `$ \bin\ls` - lists all file in your current directory and then prints the prompt on the new line.
* `$ env` - prints a list of the current environment variables.
* `$ exit` - exits out of the shell followed by a new line.

### Exiting the Shell
To exit out of our custom shell. You can use either `CTRL + D`, or `CTRL + Z` or by typing in the built-in `exit` to the command line after the `:)` prompt.

Do take note that our shell ignores the `CTRL + C` signal. As such, when entered the shell will print out the signal as `^C` and still keep you inside the shell in interactive mode. Please use the 3 above inputs to exit our shell safely. 

### Files
File Name | Description
--- | ---
[AUTHORS](https://github.com/ethanpasta/simple_shell/blob/master/AUTHORS) | This file store the contact info of all individuals who contributed to the branches of our shell code, 
[builtin_f.c](https://github.com/ethanpasta/simple_shell/blob/master/builtin_f.c) | This file is where we stord all the code we wrote for our built-in commands. It contains the code for the functions `print_env`, `exit`, `setenv` and `unsetenv`. As well as the `do_built_in` function that goes through our array of functions o search for the correct built-ins.
[enviro.c](https://github.com/ethanpasta/simple_shell/blob/B/enviro.c) | Contains 2 functions that handles copying the current environmental variable into a linked list and how to convert a linked list to an array.
[handle_path.c](https://github.com/ethanpasta/simple_shell/blob/master/handle_path.c) | Contains 2 functions that handle the PATH environmental variable. The `find_env_value` function returns the PATH in the env, while the `check_file_withP` function will check if the command exist inside the PATH directories.
[help_main.c](https://github.com/ethanpasta/simple_shell/blob/master/help_main.c) | All the functions we used in pur `main.c` file is inside this file. 
[int_string.c](https://github.com/ethanpasta/simple_shell/blob/master/int_string.c) | Where we placed our `_atoi` and `_itoa` functions.
[list_f.c](https://github.com/ethanpasta/simple_shell/blob/B/list_f.c) | The file that contains the 1st half of all the functions concerning the topic of linked lists.
[list_f2.c](https://github.com/ethanpasta/simple_shell/blob/B/list_f2.c) | The file that contains the 2st half of all the functions concerning the topic of linked lists.
[main.c](https://github.com/ethanpasta/simple_shell/blob/master/main.c) | Our entry point for the simple shell. This where the main stroke of our shell will start from.
[man_1_simple_shell](https://github.com/ethanpasta/simple_shell/blob/master/man_1_simple_shell) | The man page for our simple shell. Type in `man ./man_1_simple_shell` to see the man page on your editor.
[realloc.c](https://github.com/ethanpasta/simple_shell/blob/master/realloc.c) | The file where the `_realloc` function is written.
[shell_head.h](https://github.com/ethanpasta/simple_shell/blob/master/shell_head.h) | Our header file that contains all the libraies we used and all our prototypes we created. As well as the 2 structs we created.
[string_f.c](https://github.com/ethanpasta/simple_shell/blob/master/string_f.c) | This where all our custom built string functions are stored. i.e `_strlen`, `_puts`
[string_f2.c](https://github.com/ethanpasta/simple_shell/blob/B/string_f2.c) | Another file that contains more functions that are related to strings.
[string_split.c](https://github.com/ethanpasta/simple_shell/blob/master/string_split.c) | Where we created our custom built strtok function we name `strtow`.

### Output
* After you compilied the program, you can check to see if you  have the exact same output as `sh` (`/bin/sh`) as well as the exact same error output.
```
$ echo "qwerty" | /bin/sh
/bin/sh: 1: qwerty: not found
$ echo "qwerty" | /bin/../bin/sh
/bin/../bin/sh: 1: qwerty: not found
$
```
* The only difference is when you print an error, the name of the program must be equivalent to your `argv[0]`.
```
$ echo "qwerty" | ./hsh
./hsh: 1: qwerty: not found
$ echo "qwerty" | ./././hsh
./././hsh: 1: qwerty: not found
$
```

### Interactive Mode
Our shell should work like this in interactive mode:
```
$ ./hsh
($) /bin/ls
AUTHORS handle_path.c  int_string.c  main.c
($)
($) exit
$
```

### Non-Interactive Mode
Also, our shell should work like this in non-interactive mode:
```
$ echo "/bin/ls" | ./hsh
AUTHORS handle_path.c  int_string.c  main.c
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
AUTHORS handle_path.c  int_string.c  main.c
AUTHORS handle_path.c  int_string.c  main.c
$
```
### Built-in Commands
Here are the list of built-in commands we made for our custom shell. Included in the description are examples of what each built-in is capable of.

Each one of our custom built-in functions can be compared to the actual shell output for testing purposes using the `sh` command outside of our custom shell. With `sh` you can see if our built-in replicates the same output as a actual would.
* **exit**
  * Usage - `$ exit` or `$ exit 98`
  * When entered, it will Exit the user out of our custom shell.
  * You can doubl check if the built-in command worked by typing in `echo $?` and see if the out is the number you typed after the `exit` built-in. If the default `exit` is used, the number will always be 1. 

* **env**
  * Usage - `$ env`
  * When entered, it will Print the current environment.

* **setenv**
  * Usage - `$ setenv [VARIABLE] [VALUE]`
  * When entered, it will initialize a new environment variable, or modify an existing one.
  * Should print something on stderr upon failure.

* **unsetenv**
  * Usage - `$ unsetenv [VARIABLE]`
  * When entered, it will remove an environment variable.
  * Should print something on stderr upon failure.

* **cd**
  * Usage - `$ cd [DIRECTORY]`
  * When entered, it will change the current directory of the process.
  * If no argument is given to `cd` the command will be interpreted like `cd $HOME`.

### Bugs
Our custom-made shell is not perfect. It has some memory leaks.

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
