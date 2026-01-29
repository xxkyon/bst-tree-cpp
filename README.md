# Binary Search Tree Student Management (BST)

---

## Overview

This project is a **C++ program** that implements a **Binary Search Tree (BST)** to manage student records. Users can insert, remove, search, update students, and print the tree in **pre-order, in-order, and post-order**.

The goal is to showcase practical knowledge of **data structures, pointers, recursion, and object-oriented programming in C++**, while demonstrating clean input validation and user interaction.

---

### 1. Student Management

* Each student has a unique **ID** and a **name**.
* The tree naturally prevents duplicate IDs, reinforced in **main**.
* If an ID already exists, the user can:
  1. Update the existing student’s name.
  2. Cancel and re-enter the ID.

This ensures **data integrity** while handling user mistakes.

---

### 2. Input Validation (utils.cpp & utils.h)

* **IDs** must be integers. Non-integer input is rejected.
* **Names** cannot contain numbers, but can include:
  * Spaces (for full names)
  * Accented characters (e.g., "José da Silva")
* Extra spaces are normalized:
  * Leading and trailing spaces removed
  * Consecutive internal spaces reduced to one
* Achieved with a custom **normalizeSpaces** function that:
  1. Iterates over each character
  2. Tracks if the last character was a space
  3. Builds a clean string
  4. Removes trailing spaces with **pop_back**

This keeps data **clean and consistent**.

---

### 3. Binary Search Tree (binaryTree.cpp & binaryTree.h)

* Each node stores a **Student** object and left/right child pointers.
* Standard BST logic for insertion, removal, and search.
* **Duplicate IDs prevented**.
* **Deletion handles three cases**:
  1. Node with no children
  2. Node with one child
  3. Node with two children (in-order successor used)

---

### 4. Tree Printing

* Print orders supported:
  * **Pre-order:** Root → Left → Right
  * **In-order:** Left → Root → Right
  * **Post-order:** Left → Right → Root

Helps **visualize tree structure** and student ordering.

---

### 5. User Interaction (main.cpp)

* Menu-based system for insert, remove, search, and print
* Repeated operations until exit
* Handles duplicates as described above
* Menu output:
  * Uses blank lines and hashtags to separate iterations
  * Improves clarity without clearing the terminal

---

## How to Compile and Run

1. Navigate to the **project folder** in your terminal:

    cd bst-tree-cpp

2. Compile all source files, including the header folder:

    g++ src/*.cpp -Iinclude -o bst

* `src/*.cpp` → compiles all `.cpp` files in `src/`
* `-Iinclude` → tells compiler where headers are
* `-o bst` → generates executable `bst`

3. Run the program:

    ./bst      # Linux / macOS
    bst.exe    # Windows

4. Follow the menu prompts to manage student records.

---

## Example Usage

```
###################################
Type in 0 to stop the algorithm!
Type in 1 to insert an element!
Type in 2 to remove an element!
Type in 3 to search for an element!
Type in 4 to print the tree!

Type in an option: 1
Type in the student's ID: 101
Type in the student's name: André Schiavone
Student inserted successfully.

Type in an option: 4
Type in 1 to print in pre-order!
Type in 2 to print in order!
Type in 3 to print in post-order!
Type in an option: 2

André Schiavone: 101
```

---

## Potential Improvements

* Extend name validation for additional special characters
* Implement file I/O to save/load student data
* Add sorting by name or other criteria
* Improve UI with clearer prompts or colors

