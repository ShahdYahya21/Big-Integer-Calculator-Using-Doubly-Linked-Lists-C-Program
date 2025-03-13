# Big Integer Calculator Using Doubly Linked Lists (C Program)

This C program implements a big integer calculator that can perform basic arithmetic operations (addition, subtraction, multiplication, and division) on large numbers using doubly linked lists.

## Core Linked List Operations

- **MakeEmpty()** – Initializes an empty doubly linked list.
- **InsertAtLast()** – Adds a digit at the end of the linked list.
- **PrintList()** – Displays a number stored in a linked list.
- **Find()** – Searches for a specific digit.
- **FindLast()** – Retrieves the last node of a list.
- **Delete()** – Deletes a specific digit from the list.
- **DeleteList()** – Frees all allocated memory.
- **Insert()** – Inserts a digit at a specified position.
- **InsertChar()** – Inserts a character (for sign handling).
  
## Arithmetic Operations
The program supports the following arithmetic operations:

- **`Sum(struct Node* l1, struct Node* l2)`**: Adds two numbers and returns the result as a linked list.
- **`Sub(struct Node* l1, struct Node* l2, int digitDifference)`**: Subtracts `l2` from `l1` while considering digit differences.
- **`Mul(struct Node* l1, struct Node* l2)`**: Multiplies two numbers and returns the result.
- **`Divide(struct Node* dividend, struct Node* divisor, int numOfDividendDigit, int numOfDivisorDigit)`**: Divides `dividend` by `divisor` and returns both quotient and remainder.


## Features
- Handles **arbitrarily large integers**  
- Uses **doubly linked lists** for efficient number representation  
- Supports **negative numbers**  
- Reads numbers from **input.txt**  
- Performs **addition, subtraction, multiplication, and division**  
