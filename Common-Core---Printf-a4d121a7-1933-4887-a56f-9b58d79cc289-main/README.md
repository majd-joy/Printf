*This activity has been created as part of the 42 curriculum by majbdour.*

# ft_printf

## Description

The **ft_printf** project is a fundamental milestone in the 42 curriculum. The goal is to recode the libc's `printf` function, mimicking its behavior and formatting capabilities. This project serves as a deep dive into **variadic functions** in C and challenges us to build a structured, extensible architecture for handling diverse data types.

The function must handle the following conversions:

* `%c` (Character)
* `%s` (String)
* `%p` (Pointer address)
* `%d` / `%i` (Signed decimal integers)
* `%u` (Unsigned decimal integers)
* `%x` / `%X` (Hexadecimal lowercase/uppercase)
* `%%` (Percent sign)

---

## Instructions

### Compilation

The project is designed to be compiled into a library named `libftprintf.a`. You can use the provided **Makefile** to manage the build process.

```bash
# To compile the library
make

# To remove object files
make clean

# To remove object files and the library
make fclean

# To rebuild everything
make re

```

### Execution

To use `ft_printf` in your own C project, include the header and link the compiled library:

1. Include the header in your code: `#include "ft_printf.h"`
2. Compile your code with the library:

```bash
cc main.c -L. -lftprintf -o my_program

```

---

## Technical Choices: Algorithm and Data Structures

### The Algorithm: "Single-Pass Dispatcher"

The core logic of this implementation follows a **single-pass parsing algorithm**.

1. **Iterate**: The function traverses the format string character by character.
2. **Literal Printing**: If the character is not `%`, it is printed directly to the output.
3. **Detection & Dispatch**: Upon encountering a `%`, the algorithm "looks ahead" to the next character. Instead of using a complex state machine (which is often overkill for this basic version), I implemented a **Dispatcher Pattern** using a `switch` statement or a lookup mechanism.
4. **Variadic Access**: Based on the detected specifier, the function uses `va_arg` to pull the correctly typed data from the stack and passes it to a specific sub-function (e.g., `ft_putnbr_hex`).

### Data Structures

Because the requirements for this version of `printf` are linear, I opted for a **modular functional approach** rather than complex data structures like linked lists or trees.

* **Variadic Lists (`va_list`)**: This is the primary "data structure" used. It allows the function to navigate the memory stack where the optional arguments are stored.
* **Recursion for Base Conversion**: For integers and hexadecimal conversions, I utilized **recursive algorithms**. This avoids the need for temporary string buffers (arrays), keeping the memory footprint minimal while handling number reversals naturally through the call stack.

---

## Resources

### References

* [Secrets of printf](https://www.google.com/search?q=https://www.cypress.com/file/54441/download): A classic deep dive into the inner workings of the function.
* [Man printf(3)](https://man7.org/linux/man-pages/man3/printf.3.html): The official documentation for behavior parity.
* [Variadic Functions in C](https://en.cppreference.com/w/c/variadic): Documentation on `stdarg.h`.

### AI Usage

AI was utilized in the following capacity for this project:

* **Refactoring**: Used to suggest more concise ways to handle the hexadecimal recursion.
* **Edge Case Brainstorming**: AI helped identify tricky scenarios, such as printing the minimum value of an integer (`-2147483648`) and handling `NULL` pointers in `%p`.
* **Documentation**: AI assisted in formatting this README and structuring the technical justification section.

Majd A. Bdour DS&AI.

