# ShellB

 ShellB is a custom Shell with some new features and rework functionalities.
Lets take a look in this features:

---

### Default functions rework
  
Standard commands like "cd", "ls" and etc are remakes for a lot of reasons, for exemple:
ShellB can auto-compile and have functionalities to custom the default commands. So, if you want modify the "ls" command, go ahead.
You can rework all the shell if you want (even the name if you want).

---

### Custom Script Language

Yes, ShellB have a custom language called "SB Script". You can use all the functions of ShellB directly in SB Script file (like .sh files).
You also can modify the script if you want (ShellB have a command to compile the language file).

---

### Custom ShellB commands

### -> cf

CF ( or Create Folder ) is the remake of "mkdir".

### -> re

RE ( or rename ) basically renames a file.

How to use: re {file that you want to change the name} {new name}

### -> rm

RM ( or remove ) is the rework of default "rm".

Same way to use but don't need parameters, exemple: rm {file you want to remove}

### -> ram

RAM - Prints the ShellB's ram usage.

### -> exit

EXIT - Just exit...

### -> nf

NF - Based on neofetch. Prints the system info.

### -> shutdown

SHUTDOWN - Just a shutdown but don't need args. (if you using windows or try to use in wsl maybe don't work)

### -> mkf

MKF ( or makefile ) Creates a file.
How to use: "mkf exemple.c"

## Note:

ShellB runs commands in system level by default. If some command "don't exist" ShellB will execute in system level.

For exemple: Npm commands or compilers like clang are external commands, so ShellB will execute them equally but in system level using you default shell.

---

### Currently ShellB have more commands, but i will talk about them and the script language in the future.
