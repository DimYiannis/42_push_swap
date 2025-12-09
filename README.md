*This project has been created as part of the 42 curriculum by ydimitra.*

# Push_Swap

## Description

Push_Swap is a project from the 42 curriculum whose goal is to sort a list of integers using two stacks (`stack_a` and `stack_b`) and a restricted set of operations.  
The challenge is to produce the **shortest possible sequence of instructions** to sort the integers in ascending order.

The program must:
- Validate and parse input.
- Detect duplicates and invalid integers.
- Manage memory safely.
- Output only the required sorting operations.
- Use an efficient algorithm to minimize the number of operations.

---

## Instructions

### ✔️ Compilation

Run `make` to generate the `push_swap` executable.

To remove object files, use `make clean`.

To fully clean all compiled files, use `make fclean`.

To recompile everything from scratch, use `make re`.

---

### ✔️ Execution

Run the program followed by a list of integers as arguments:

./push_swap 4 2 5 1 6 3

To verify the result using the 42 checker:

./push_swap 4 2 5 1 6 3 | ./checker_linux 4 2 5 1 6 3




## Features

Sorting using restricted operations

Duplicate detection

Integer overflow checking

Memory-safe implementation (all allocations freed)

Random input example:

./push_swap 3 9 1 7 2


Check with Valgrind:

valgrind --leak-check=full ./push_swap 5 4 6 2 1 3

## Resources
### 📚 Documentation & Algorithms

42 Subject PDF

Stack operations theory

Sorting with stacks – concepts & examples

Time complexity of sorting algorithms

Circle linked list structures

## 🤖 AI Usage Disclosure (Required by 42)

AI was used only for:

Generating the README structure and improving clarity

Explaining Turk algorithm

Assistance in debugging memory leaks by interpreting Valgrind output

Helping restructure functions for readability

No AI-generated code was directly used in the final project.
All logic and implementation were written manually following 42 standards.

Author

ydimitra
42 Codam can you help me fix the mistakes?

