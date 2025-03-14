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


## Program Output Example
When running the calculator, the user is presented with the following menu:

Welcome to my calculator  
Select one operation:  
1. Read the input file  
2. Add  
3. Subtract  
4. Multiply  
5. Divide  
6. Print the results to an output file  
7. Exit

---

#### If the User Chooses 1: Read Input File  
The following numbers are available for operations:
1. 1111111111  
2. 222  
3. -2  
4. 242485  
5. -234254  
6. 32242542425

---

#### If the User Chooses 2: Add  
The user selects the numbers by entering options 1 and 2. The numbers selected are 1111111111 and 222. The calculator performs the addition:  
**Sum**: 1111111333

---

#### If the User Chooses 3: Subtract  
The user selects the numbers by entering options 1 and 2 again. The selected numbers are 1111111111 and 222. The calculator performs the subtraction and returns:  
**Result**: 1111110889

---

#### If the User Chooses 4: Multiply  
The user selects the numbers by entering options 1 and 2. The numbers selected are 1111111111 and 222. The calculator performs the multiplication:  
**Result**: 246666666642

---

#### If the User Chooses 5: Divide  
The user selects numbers 1 and 2 again. The selected numbers are 1111111111 and 222. The calculator performs the division and returns:  
- **Quotient**: 5005005  
- **Remainder**: 1

---

#### If the User Chooses 6: Print the Results to an Output File  
The calculator will print the results of the previous operations to an output file.

---

#### If the User Chooses 7: Exit  
#### The user exits the calculator program.
---

