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

These operations are implemented using the following functions:

- **Sum(struct Node* l1, struct Node* l2)**: Adds two numbers.
- **Sub(struct Node* l1, struct Node* l2, int digitDifference)**: Subtracts two numbers.
- **Mul(struct Node* l1, struct Node* l2)**: Multiplies two numbers.
- **Divide(struct Node* dividend, struct Node* divisor, int numOfDividendDigit, int numOfDivisorDigit)**: Divides two numbers and returns quotient and remainder.

## Notes

- The program reads large numbers from a file (`input.txt`) and stores them in an array of doubly linked lists.
- Negative numbers are handled by storing a sign attribute in the linked list.
- The program allows the user to **add, subtract, multiply, and divide** two selected numbers.
