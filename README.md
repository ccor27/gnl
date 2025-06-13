
# GNL

This is a 42 project to implement a function in C (get_next_line) able to read a line from a file descriptor of file, including *\n*. Each call of the function should return the next line of the file until the end of it be reached o there be an error.

## Main objective

The main objective of this project is to become familiar with:

**File Descriptors (File Descriptors - FDs):** Understand how to interact with files at the operating system level using functions such as *open()*, *read()*, and *close()*.

**Dynamic Memory Management:** Implement a robust solution that handles the allocation, reallocation and release of memory in an efficient way to build the read lines, regardless of their size. This includes the use of *malloc()*, *free()*, and possible auxiliary functions like *strjoin* or *strdup*.

**Static Variables (static):** Understand and apply the use of static variables to maintain a persistent state between calls to the function, which allows storing the data left over from one reading that is not part of the current line but of the next.

**Error Handling:** Implement mechanisms to detect and manage read errors, invalid file descriptors and memory allocation issues, returning *NULL* when appropriate.

## Bonus part (multiple files)

The bonus part extends functionality to ensure that get_next_line can correctly read from multiple file descriptors simultaneously without mixing their buffers or losing data, demonstrating effective state handling by each FD.

## How use it?

### clone the repo
- git clone https://github.com/ccor27/gnl
- cd gnl

### Compile and test

There are three ways to compile and test it, usign the files that are in the folders test_cases and test_cases_bonus:

- *make test_mandatory* (just for mandatory)
- *make test_bonus* (just for bonus)
- *make* (for both mandatory and bonus)

Tests use different buffer sizes and invalid fds are tested.
The code was built to handle error cases during read or memory allocation, however there is no proof for those cases.
