### **Binary Search Tree Student Management (BST)**



#### **Overview**



This project is a **C++ program** that implements a **Binary Search Tree (BST)** to manage student records. It allows users to insert, remove, search, and update students, as well as print the tree in **pre-order, in-order, and post-order**.



The goal of this project is to showcase practical knowledge of **data structures, pointers, recursion, and object-oriented programming in C++**, while also demonstrating how input validation and user interaction can be handled in a clean and structured way.

---

#### **Key Features \& Design Decisions**



#### **1. Student Management**



* Each student has a unique **ID** and a **name**.



* The tree itself naturally prevents duplicate IDs, and this is reinforced in the **main** function.



* If a user tries to insert a student with an existing ID, the program offers **two options:**



&nbsp;	###### **1.** Update the existing student’s name.



&nbsp;	###### **2.** Cancel the operation and re-enter the ID.



This approach ensures data integrity while giving flexibility to handle user mistakes.
---
###### 

#### **2. Input Validation (utils.cpp \& utils.h)**



* **IDs** must be integers. Any non-integer input is rejected.



* **Names** cannot contain numbers. They can contain:



&nbsp;	**1.** Spaces (allowing full names)



&nbsp;	**2.** Accented characters (supports names like "José da Silva")



* **Extra** spaces are automatically normalized:



&nbsp;	**•** Leading and trailing spaces are removed.



&nbsp;	**•** Consecutive spaces inside the string are reduced to a single space.



* This is achieved with a custom **normalizeSpaces** function, which:



&nbsp;	**1.** Iterates over each character in the input.



&nbsp;	**2.** Tracks whether the last character was a space.



&nbsp;	**3.** Builds a clean version of the string with proper spacing.



&nbsp;	**4.** Removes trailing spaces using **pop\_back**.



This validation ensures **clean, consistent data**, while being flexible enough for realistic names.

---

#### **3. Binary Search Tree (binaryTree.cpp \& binaryTree.h)**



* Each node stores a **Student** object and has left and right child pointers.



* Insertion, removal, and search operations follow standard BST logic.



* **Duplicate IDs are prevented:**



&nbsp;	• The tree will not insert a node if a student with the same ID exists.



* **Deletion handles three cases:**



&nbsp;	**1.** Node with no children.



&nbsp;	**2.** Node with one child.



&nbsp;	**3.** Node with two children (in-order successor is used).

---

#### **4. Tree Printing**



* The tree can be printed in three orders:



&nbsp;	• **Pre-order:** Root → Left → Right



&nbsp;	• **In-order:** Left → Root → Right



&nbsp;	• **Post-order:** Left → Right → Root



This allows visualization of the tree structure and student ordering.

---

#### **5. User Interaction (main.cpp)**



**Menu-based system with options to insert, remove, search, and print the tree:**



* Allows **repeated operations** until the user chooses to exit.



* Enforces **duplicate handling**, as mentioned above.



* Demonstrates structured input **validation** and **user feedback**.



* Readable menu output:



&nbsp;	• Instead of clearing the terminal each time, the menu separates iterations with blank lines and hashtags.



&nbsp;	• Improves clarity and prevents confusion about previous inputs or outputs.


---
##### 

#### **How to Compile and Run**



1. Navigate to **the project folder** in the terminal:

   	*cd bst-tree-cpp*
   
2. Compile **all source files together**, specifying the include folder for header files:

   	*g++ src/\*.cpp -Iinclude -o bst*


  ###### • **src/\*.cpp** compiles **all .cpp files** in the **src** folder.

  ###### • **-Iinclude** tells the compiler where to find **header files**.

  ###### • **-o bst** generates the **executable** named **bst**.
   
3. **Run** the program:

   ./bst   *# Linux / macOS*
   bst.exe *# Windows*

   
4. Follow the **menu prompts** to manage student records.

###### 
---
#### **Example Usage:**



\###################################

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


---
#### **Potential Improvements**



* Extend name validation to allow other special characters if needed.



* Implement file I/O to save/load student data.



* Add sorting by name or other criteria.



* Improve the user interface with clearer prompts or colors.

