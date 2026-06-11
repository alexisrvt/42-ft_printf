*This project has been created as part of the 42 curriculum by arivet.*

# ft_printf

## Description
The goal of this project is to recode the standard C library `printf` function.
It also teach us about variadic arguments in C. This implementation handles the mandatory conversion specifiers (`c`, `s`, `p`, `d`, `i`, `u`, `x`, `X`, `%`) as well as the bonus formatting flags (`-`, `0`, `.`, `#`, ` `, `+`) and minimum field width management.

## Detailed Algorithm and Data Structure
**Data Structure:**
The project relies on a central `t_format` struct. When a `%` symbol is encountered, this structure is zeroed out and populated with the parsed flags, width, precision, and conversion type. 
*Justification:* Using a structure allows the codebase to be highly modular and readable. It also helps respecting the Norm and its limits on how many functions, parameters and lines are allowed. 

**Algorithm:**
For the algorithm, my idea was not to use `malloc` at all, focusing mainly on direct `write` calls to prevent any risk of memory leaks.
1. **Parsing:** The string is read sequentially. Upon finding `%`, a parsing function extracts the formatting rules and stores them in the `t_format` structure, advancing the main string index automatically.
2. **Dispatching:** A dispatcher reads the `type` field of the structure, extracts the correct type from the `va_list`, and redirects it to the specific printing function.
3. **Mathematical Formatting:** Instead of building a final string in allocated memory, the algorithm calculates the required padding (spaces or zeros) based on the argument's base length, the requested precision, and the field width. It then executes a sequence of `write` respecting the rules order.

## Instructions
### Compilation
To compile the library, simply run the following command at the root of the repository:
```bash
make

```

This will generate the `libftprintf.a` static library. Since the bonus features are integrated directly into the core logic, you can also run:

```bash
make bonus

```

### Usage

Include the header in your C files:

```c
#include "ft_printf.h"

```

Compile your program with the compiled library:

```bash
cc -Wall -Wextra -Werror your_file.c -L. -lftprintf -o your_program

```

## Resources

* **Documentation:** `man 3 printf`, `man 3 stdarg` for standard library behavior and variadic argument management.
* **C Reference:** Standard C documentation for detailed edge cases regarding `printf` flag priorities.
* **AI Usage:** AI was used as an interactive documentation tool, especially to better understand the variadic argument management, otherwise all logic and code were written manually to build foundational understanding.