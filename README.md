# mysh

**mysh** is a custom Unix shell developed in C, inspired by the TCSH shell. Designed as a robust and interactive command-line interpreter, it replicates many features of a standard shell with additional support for job control, globbing, line editing, and command history.

## 🚀 Features

- 🧠 **Inhibitors and Globbing**: Supports quotes (`'`, `"`) and wildcards (`*`, `?`, `[ ]`) for flexible command patterns.
- 🧮 **Command Substitution**: Supports backtick expressions (`` `command` ``).
- 🧩 **Parentheses & Grouping**: Run grouped commands using `()`.
- 🌍 **Environment & Local Variables**: Includes support for shell variables and special variables like `$TERM`, `$cwd`, etc.
- 📜 **History & Aliases**: Command history with `!`, and alias creation for custom shortcuts.
- 🛠️ **Line Editing & Auto-Completion**: Dynamic keybindings and multi-line support.

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
./mysh
