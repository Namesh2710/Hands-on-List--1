# System Software Lab

This repository contains the implementations of 30 System Software lab programs using C on Linux/WSL Ubuntu.

## Environment

- Language: C
- Operating System: Ubuntu Linux / WSL
- Compiler: GCC

## Programs

| No. | Program |
|-----|---------|
| 01 | File types using shell commands and system calls: soft link, hard link, FIFO |
| 02 | Infinite loop process and `/proc` inspection |
| 03 | Create a file and print file descriptor using `creat()` |
| 04 | Open an existing file and demonstrate `O_EXCL` |
| 05 | Create five files and inspect `/proc/<pid>/fd` |
| 06 | Copy STDIN to STDOUT using `read()` and `write()` |
| 07 | Copy one file into another |
| 08 | Read and display a file line by line |
| 09 | Display file information using `stat()` |
| 10 | File positioning using `lseek()` |
| 11 | Duplicate file descriptors using `dup()`, `dup2()` and `fcntl()` |
| 12 | Find file opening mode using `fcntl()` |
| 13 | Wait for STDIN using `select()` |
| 14 | Identify file type using `lstat()` |
| 15 | Display environment variables using `environ` |
| 16 | File locking using `fcntl()` |
| 17 | Ticket reservation using write locking |
| 18 | Record locking |
| 19 | Measure `getpid()` using timestamp counter |
| 20 | Process priority and `nice` |
| 21 | Create parent and child processes using `fork()` |
| 22 | Parent and child writing to the same file after `fork()` |
| 23 | Create a zombie process |
| 24 | Create an orphan process |
| 25 | Create multiple children and use `waitpid()` |
| 26 | Execute another program using `exec()` |
| 27 | Execute `ls -Rl` using different `exec()` variants |
| 28 | Find minimum and maximum real-time priority |
| 29 | Get and modify scheduling policy |
| 30 | Run a script using a daemon process |

## Directory Structure

Each program is organized in its own directory:

```text
01_file_links/
02_infinite_process/
03_creat/
...
30_daemon/
