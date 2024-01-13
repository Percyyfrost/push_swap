 # Push_swap

## Project Overview

This project challenges you to implement an efficient sorting algorithm using a limited set of instructions to manipulate two stacks: Stack A and Stack B. The goal is to sort a given list of numbers in ascending order within Stack A, using as few actions as possible.

## Rules and Constraints

- Initial State: Stack A holds the unsorted list of numbers, while Stack B is empty.
- Allowed Actions:
    - `sa`: Swap the top two elements of Stack A.
    - `sb`: Swap the top two elements of Stack B.
    - `ss`: Swap the top elements of both Stack A and Stack B.
    - `pa`: Push the top element of Stack B onto Stack A.
    - `pb`: Push the top element of Stack A onto Stack B.
    - `ra`: Rotate the elements of Stack A upwards.
    - `rb`: Rotate the elements of Stack B upwards.
    - `rr`: Rotate the elements of both Stack A and Stack B upwards.
    - `rra`: Rotate the elements of Stack A downwards.
    - `rrb`: Rotate the elements of Stack B downwards.
    - `rrr`: Rotate the elements of both Stack A and Stack B downwards.
- Final State: Stack A must contain the sorted list of numbers in ascending order, and Stack B must be empty.

## Usage

1. Compile the program using the provided Makefile:
    ```bash
    make
    ```
2. Run the program with a list of numbers as arguments:
    ```bash
    ./push_swap 5 2 8 1 9
    ```
3. The program will output the sequence of actions required to sort the numbers.

## Checker Program

A separate checker program, `checker`, is provided to verify the correctness of the sorting algorithm. To use it:

1. Pipe the output of `push_swap` into the `checker` program, along with the original list of numbers:
    ```bash
    ./push_swap 5 2 8 1 9 | ./checker 5 2 8 1 9
    ```
2. The `checker` program will output `OK` if the numbers are sorted correctly, or `KO` if not.

## Evaluation

Your solution will be evaluated based on two criteria:

- Correctness: The program must correctly sort all valid input lists.
- Efficiency: The program should use as few actions as possible to sort the numbers.

## Additional Notes

- Consider using a visualizer tool to help you understand the behavior of the stacks and actions.
- Experiment with different sorting algorithms and strategies to optimize performance.
- Aim for a clear and concise implementation that is easy to understand and maintain.
