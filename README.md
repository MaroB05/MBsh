## MBsh (MaroB shell)

A simple shell implementation in C.

### Features

* Reads input from stdin or files
* Executes commands using `fork` and `execlp`
* Supports basic command-line interaction (no arguments yet)

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

* Currently only supports a limited set of commands
* Error handling is minimal

