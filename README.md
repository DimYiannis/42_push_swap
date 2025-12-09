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

### Compilation
```bash
make
```

### Usage
```bash
# Multiple arguments
./push_swap 3 2 5 1 4

# Single string
./push_swap "3 2 5 1 4"

# Test with checker
ARG="3 2 5 1 4"; ./push_swap $ARG | ./checker_linux $ARG
```

### Cleaning
```bash
make clean   # Remove object files
make fclean  # Remove object files and executable
make re      # Recompile
```
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

- Turk Algorithm explanation

- [Push_Swap Turk algorithm explained in 6 steps] (https://pure-forest.medium.com/push-swap-turk-algorithm-explained-in-6-steps-4c6650a458c0)

- [Push Swap — A journey to find most efficient sorting algorithm] (https://medium.com/@ayogun/push-swap-c1f5d2d41e97)

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
42 Codam 

