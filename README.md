## MBsh (MaroB shell)

A simple shell implementation in C.

### Features

* Reads input from stdin or files
* Executes commands using `fork` and `execvp`
* Supports basic command-line interaction

### Build and Run

To build and run MBsh, use the following commands:

```bash
make compile
```

### Example Use Cases

* Run MBsh with no arguments to enter interactive mode
```bash
 ./build/MBsh.out
```

* Pass a file as an argument to execute commands from that file
```bash
 ./MBsh.out file1 [file2 ...]
```

### Known Limitations

* Currently doesn't support internal commands (e.x. `exit`)
* Error handling is minimal

