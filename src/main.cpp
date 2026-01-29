#include <iostream>
#include <string>
#include "binaryTree.h"
#include "utils.h"

int main(){
    BinarySearchTree studentTree;

    int option, id, printOption;

    std::string name;

    do{ std::cout << std::string(3, '\n');
        std::cout << "###################################\n";
        std::cout << "Type in 0 to stop the algorithm!\n";
        std::cout << "Type in 1 to insert an element!\n";
        std::cout << "Type in 2 to remove an element!\n";
        std::cout << "Type in 3 to search for an element!\n";
        std::cout << "Type in 4 to print the tree!\n";
        std::cout << "\n\n";
        option = readInt("Type in an option: ");
        std::cout << "\n\n";
        if(option == 1){
            id = readInt("Type in the student's ID: ");
            Student foundStudent;

            bool exists = studentTree.search(id, foundStudent);

            if(exists){
                std::cout << "There's a student registered with the same Id.\n";
                std::cout << "\n\n";
                std::cout << "Would you like to: \n";
                std::cout << "1. Update existing registration with a new name\n";
                std::cout << "2. Return and retype the ID\n";
                std::cout << "\n\n";
                int choice = readInt("Type your answer: ");

                if(choice == 1){
                    name = readString("Type in the new student's name: ");
                    studentTree.updateStudentName(id, name);
                    std::cout << "\n\n";
                    std::cout << "Student updated succesfully.\n";
                } else if(choice == 2){
                    std::cout << "\n\n";
                    std::cout << "Operation cancelled. Returning to the menu.\n";
                } else{
                    std::cout << "\n\n";
                    std::cout << "Invalid option. Returning to the menu.\n";
                }
            } else {
                std::cout << "\n\n";
                name = readString("Type in the student's name: ");
                Student student(id, name);
                studentTree.insert(student);
                std::cout << "\n\n";
                std::cout << "Student inserted successfully.\n";
            }
            
        } else if (option == 2){
                    std::cout << "\n\n";
            id = readInt("Type in the ID of the student you want to remove:\n");
            Student student(id, " ");
            studentTree.remove(student);
        } else if (option == 3){
            std::cout << "\n\n";
            id = readInt("Type in the ID of the student you want to search!\n");

            Student student;
            bool found = studentTree.search(id, student);

            if(found){
                std::cout << "\n\n";
                std::cout << "The student has been found!\n";
                std::cout << "Name: " << student.getName() << std::endl;
                std::cout << "ID: " << student.getId() << std::endl;
            } else {
                std::cout << "\n\n";
                std::cout << "The student hasn't been found!\n";
            } 
        } else if (option == 4){
            std::cout << "\n\n";
            std::cout << "Type in 1 to print in pre-order!\n";
            std::cout << "Type in 2 to print in order!\n";
            std::cout << "Type in 3 to print in post-order!\n";
            std::cout << "\n\n";
            printOption = readInt("Type in an option: ");
            std::cout << "\n\n";
            if(printOption == 1){
                studentTree.printPreOrder();
            } else if(printOption == 2){
                studentTree.printInOrder();
            } else if(printOption == 3){
                studentTree.printPostOrder();
            } else{
                std::cout << "\n\n";
                std::cout << "Invalid print option.\n";
            }
        } else if(option < 1 || option > 4){
            std::cout << "\n\n";
            std::cout << "Invalid option.\n";
        }
        
    } while (option != 0);

    return 0;
}