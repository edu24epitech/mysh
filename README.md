# mysh

**mysh** is a custom Unix shell developed in C, inspired by the TCSH shell. Designed as a robust and interactive command-line interpreter, it replicates many features of a standard shell with additional support for job control, globbing, line editing, and command history.

## 🚀 Features

- Execute binary commands using environment PATH or direct paths
- Built-in commands: `cd`, `env`, `setenv`, `unsetenv`, `exit`
- Command separators using semicolons (`;`)
- Pipe support (`|`) between multiple commands
- Redirection support:
  - Output redirection: `>`
  - Input redirection: `<`
  - Append redirection: `>>`
  - Heredoc redirection: `<<`
- Proper signal and error management
- Returns the correct exit status from executed commands

## 🧱 Tech Stack

- **Language**: C (libC + ncurses)
- **Build System**: Makefile (`make`, `make re`, `make clean`, `make fclean`)
- **Unit Testing**: Custom tests built during development

## 🧪 Getting Started

### Requirements

- Unix-like OS
- GCC compiler
- `ncurses` library

### Compilation

```bash
make

```
```bash
./mysh
```
## 💡 Example Usage

```bash
> pwd
/home/user/projects

> cd ..
> pwd
/home/user

> ls -l ; echo "Listing completed"
total 8
drwxr-xr-x 2 user user 4096 Jun 4 09:00 folder
Listing completed

> echo "This is a test" > test.txt
# Creates a file with the line
```

