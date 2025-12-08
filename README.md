# Push_Swap

## Project Overview

Push_Swap is a sorting algorithm project.  
The goal is to sort a stack of integers with a limited set of operations, using two stacks: `stack_a` and `stack_b`.

---

## Features

- Sorts integers using only stack operations.
- Handles positive and negative numbers.
- Detects duplicates and invalid input.
- Optimized to minimize the number of operations.
- Memory-safe with all allocations freed.

---


## Logic

The sorting strategy (often referred to as the “Turk” algorithm) works as follows:

1. **Initial Push to Stack B:**  
   Push a portion of the elements from `stack_a` to `stack_b`, keeping a few elements in `stack_a` to sort directly (usually 3).

2. **Sorting Small Stack A:**  
   Sort the small number of remaining elements in `stack_a` using simple comparisons (`sa`, `ra`, `rra`).

3. **Calculating Costs:**  
   For each element in `stack_b`, calculate the “cost” to move it to the correct position in `stack_a`.  
   - The cost depends on how many rotations (`ra`/`rra`) or (`rb`/`rrb`) are needed.

4. **Move Cheapest Element:**  
   Move the element with the lowest cost from `stack_b` to `stack_a` using the optimal combination of rotations and push (`pa`).

5. **Repeat Until Stack B is Empty:**  
   Continue moving elements from `stack_b` to `stack_a` in order of minimal cost.

6. **Final Adjustment:**  
   Rotate `stack_a` until the smallest element is at the top to complete the sort.

This approach ensures that the number of operations is minimized while sorting efficiently.

---

## Stack Operations

- **Swap:** `sa`, `sb`, `ss`
- **Push:** `pa`, `pb`
- **Rotate:** `ra`, `rb`, `rr`
- **Reverse rotate:** `rra`, `rrb`, `rrr`

---

## Usage

Compile the project:

```bash
make

