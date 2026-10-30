# Low-Level File Opener and Writer (Educational Project)

A hands-on educational project written in C to demonstrate POSIX system calls, process management, and low-level file I/O operations in a Linux environment.

## 🛠️ How It Works

1. **Parent Process:** Dynamically allocates memory for the file path, reads user input character-by-character, and safely handles input buffer termination.
2. **Process Forking:** The parent spawns a child process using the `fork()` system call.
3. **Child Process:**
   - Opens or creates a file at the specified path using low-level flags (`O_RDWR | O_TRUNC | O_CREAT`) with `0644` permissions.
   - Prompts the user for a text string (up to 79 characters) and commits it to disk using the `write()` system call.
   - Replaces its execution context with the standard Linux `cat` utility via `execvp()` to print the newly written file contents back to the console immediately.
4. **Resource Management:** The parent process waits for the child to finish using `wait(NULL)`, cleans up all allocated heap memory (`free`), and exits cleanly.

## 🚀 Getting Started

### Prerequisites
A Linux-based environment with a `gcc` compiler and standard development tools.

### Compilation
Compile the source code using `gcc`:
```bash
gcc -o file_manager main.c
```

### Execution
Run the compiled binary. *Note: Ensure you provide a file path that your user has write permissions for (e.g., inside your current directory).*
```bash
./file_manager
```

## 🧠 Core Concepts Covered

* **Process Management:** Implementing multi-processing with `fork()`, handling parent-child relationships, and process synchronization with `wait()`.
* **Execution Context Switching:** Replacing a process image using `execvp()` and managing argument arrays with `strdup()`.
* **Low-Level File I/O:** Interfacing directly with the OS kernel via file descriptors using `open()`, `write()`, and `close()`.
* **Memory & Buffer Safety:** Static array initialization, tracking raw character streams, and manual heap memory lifecycles (`malloc`/`free`).

