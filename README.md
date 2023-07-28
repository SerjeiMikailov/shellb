# ShellB

 ShellB is a custom Shell with some new features and rework functionalities.
Lets take a look in this features:

---

### Default functions rework
  
Standard commands like "cd", "ls" and etc are remakes for a lot of reasons, for example:
ShellB can auto-compile and have functionalities to customize the default commands. So, if you want to modify the "ls" command, go ahead.
You can rework the entire shell (even the name if you want).

---

### Custom Script Language

Yes, ShellB has a custom language called "SB Script". You can use all the functions of ShellB directly in SB Script file (like .sh files).
You can also modify the script if you want (ShellB has a command to compile the language file).

---

### Custom ShellB commands

### -> cf

CF ( or Create Folder ) is the remake of "mkdir".

### -> re

RE ( or rename ) basically renames a file.

How to use: re {file that you want to change the name} {new name}

### -> rm

RM ( or remove ) is the rework of default "rm".

Same way to use, but doesn't need parameters. Example: rm {file you want to remove}

### -> ram

RAM - Prints the ShellB's ram usage.

### -> exit

EXIT - Just exits...

### -> nf

NF - Based on neofetch. Prints the system info.

### -> shutdown

SHUTDOWN - Just a shutdown but doesn't need args. (if you using windows or try to use in wsl maybe don't work)

### -> mkf

MKF ( or makefile ) Creates a file.
How to use: "mkf example.c"

## Note:

ShellB runs commands in system level by default. If some command "don't exist" ShellB will execute in system level.

For example: Npm commands or compilers like clang are external commands, then ShellB will execute them equally, but in system level using your default shell.

---

### Currently ShellB have more commands, but i will talk about them and the script language in the future.
