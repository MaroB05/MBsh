# MBsh (MaroB Shell)

MBsh is a simple shell implemented in C, designed to execute external programs and parse command arguments. This project focuses on understanding the basics of shell functionality, with a minimalist approach to error handling.

## Table of Contents
1. [Project Overview](#project-overview)
2. [Features](#features)
3. [Installation](#installation)
4. [Usage](#usage)
5. [How It Works](#how-it-works)
6. [Known Issues and Limitations](#known-issues-and-limitations)
7. [Future Improvements](#future-improvements)
8. [Contributing](#contributing)

---

## Project Overview

MBsh provides a basic shell environment that executes external commands, similar to `/bin/sh`. It does not currently support internal commands like `cd` or `exit`, keeping the focus on external program execution and argument parsing.

## Features

- **Program Execution:** Runs external programs (e.g., `/bin/ls`, `/bin/echo`) with specified arguments.
- **Argument Parsing:** Parses and passes command-line arguments to the programs.
- **Minimal Error Handling:** Basic error handling to manage invalid commands or missing arguments.

## Installation

1. Clone the repository:
    ```bash
    git clone https://github.com/your-username/MBsh.git
    ```

2. Navigate to the project directory:
    ```bash
    cd MBsh
    ```

3. Compile the code:
    ```bash
    make compile
    ```

## Usage

To start MBsh, run:
```bash
make run
```
or
```bash
./build/MBsh.out
```
## How It Works

### Step 1: Input and Parsing
- MBsh reads user input and splits it into the program name and arguments.
- Basic error checks are applied, such as handling empty input.

### Step 2: Specify command type:
- Based on the given command, MBsh classifies if the command is either internal or external.

### Step 3: Forking and Execution
- MBsh uses `fork()` to create a new process for executing the program in case of an external command.
- In the child process, `execvp()` is called to run the specified program with arguments.

### Step 4: Error Handling and Continuation
- Minimal error handling is in place for unrecognized commands or argument errors.
- MBsh continues prompting for new commands unless terminated.
## Known Issues and Limitations

- **Limited Internal Commands:** only implemented `cd` and `exit` as internal shell commands.
- **Limited Error Feedback:** Error handling is minimal, providing basic feedback on invalid commands.
- **No Redirection or Piping:** Features like input/output redirection and piping are not implemented.

## Future Improvements

- **Add Internal Commands:** Implement internal commands, such as `cd` and `exit`.
- **Enhanced Error Handling:** Provide more informative error messages and handle additional edge cases.
- **Support for Redirection and Piping:** Enable support for `>`, `<`, and `|` operators.
- **Job Control:** Allow commands to be run in the background with `&`.
