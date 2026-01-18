# Data Structures in C
A collection of common data structure implementations in C. This repository demonstrates both **array-based** and **linked-list-based** versions.

---

## Stack
### Array Implementation
- File: `stack-array.c`
- Operations: Push, Pop, Peek
### Linked List Implementation
- File: `stack-linkedlist.c`
- Operations: Push, Pop, Peek

---

## Queue
### Array Implementation
- File: `queue-array.c`
- Operations: Enqueue, Dequeue
### Linked List Implementation
- File: `queue-linkedlist.c`
- Operations: Enqueue, Dequeue
### Circular Array Implementation
- File: `circularqueue-array.c`
- Operations: Enqueue, Dequeue

---

## Binary Tree
### Binary Tree (Linked List)
- File: `binarytree-linkedlist.c`
- Operations: Insert left/right, Traversals (inorder, preorder, postorder)
### Binary Search Tree (Linked List)
- File: `binarysearchtree-linkedlist.c`
- Operations: Insert, Search, Delete, Traversals (inorder, preorder, postorder)

---

## Linked List
- File: `linkedlists.c`
- Operations: Sorted insert, Delete, Print

---

## Basics
### Pointers
- File: `pointers.c`
- Demonstrates: Pass-by-reference, Modifying variables via pointers
### Structs
- File: `structs.c`
- Demonstrates: Struct definition and initialization, Nested structures, Structs with pointers

---

## Skills Demonstrated
- Implementation of array-based and linked-list-based data structures
- Dynamic memory management (`malloc`, `free`)
- Explicit memory deallocation to prevent memory leaks
- Underflow and overflow handling
- Recursive and iterative traversal methods
- Pointer manipulation and struct usage

---

## How to Run
1. Navigate to the folder containing the implementation you want to run:
  ```bash
  cd stack
  ```
2. Compile the C file:
  ```bash
  gcc stack-array.c -o stack
  ```
3. Run the program:
  ```bash
  ./stack
  ```
Repeat the steps above for other data structures by navigating to their corresponding folders and compiling the .c file.
