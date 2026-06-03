*This project has been created as part of the 42 curriculum by <arivet>.*

# Libft: Your very first own library

## Description
This project involves coding a custom C library containing numerous general-purpose functions. Since standard C library functions are not always available in the curriculum's projects, `libft` serves as a foundational tool that will be reused and expanded upon throughout the curriculum. It includes reimplementations of standard `libc` functions, as well as additional utility functions for string manipulation and linked list management.

## Instructions

### Compilation
The library is compiled using a `Makefile`. To build the library, simply run the following command in the root directory:
```bash 
make
```

This will compile the source files with the required flags (`-Wall -Wextra -Werror`) and generate the `libft.a` static library.

### Additional Makefile Rules
* `make clean`: Removes all object files (`.o`).
* `make fclean`: Removes all object files and the `libft.a` binary.
* `make re`: Performs a full recompilation (`fclean` followed by `make`).
* `make bonus`: Compiles the library with the linked list bonus functions.

### Usage
To use `libft` in your future projects, include the header file in your C files:
```c
#include "libft.h"
```
Then, compile your project alongside the library:
```bash
cc -Wall -Wextra -Werror your_file.c -L. -lft
```

## Library Overview

### Part 1: Libc Functions
Re-implementations of standard C library functions, strictly adhering to their `man` page behaviors:
* **Character classification:** `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`
* **Character conversion:** `ft_toupper`, `ft_tolower`
* **String manipulation:** `ft_strlen`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strlcpy`, `ft_strlcat`, `ft_strnstr`, `ft_strdup`
* **Memory manipulation:** `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`, `ft_calloc`
* **Conversion:** `ft_atoi`

### Part 2: Additional Functions
Utility functions not included in the standard `libc`:
* `ft_substr`: Extracts a substring from a string.
* `ft_strjoin`: Concatenates two strings.
* `ft_strtrim`: Removes specified characters from the beginning and end of a string.
* `ft_split`: Splits a string into an array of strings using a delimiter.
* `ft_itoa`: Converts an integer to a string.
* `ft_strmapi` & `ft_striteri`: Applies a function to each character of a string.
* `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`: Outputs text or numbers to a specific file descriptor.

### Part 3: Linked List Functions
Functions to manipulate a custom linked list structure (`t_list`):
* **Node creation and insertion:** `ft_lstnew`, `ft_lstadd_front`, `ft_lstadd_back`
* **List information:** `ft_lstsize`, `ft_lstlast`
* **Memory management:** `ft_lstdelone`, `ft_lstclear`
* **Iteration and mapping:** `ft_lstiter`, `ft_lstmap`

## Resources
* **Documentation:** Standard C `man` pages (e.g., `man 3 strlen`), [cppreference.com](https://en.cppreference.com/w/c).
* **AI Usage:** AI was used as an interactive documentation tool to better understand the behavior of edge cases in memory overlap, especially for `ft_lstmap` and `ft_calloc`, but all logic and code were written manually to build foundational understanding.