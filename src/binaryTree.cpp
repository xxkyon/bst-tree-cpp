#include <iostream>
#include <cstddef> 
#include "binaryTree.h"

BinarySearchTree::BinarySearchTree(){
    root = nullptr;
}
BinarySearchTree::~BinarySearchTree(){ 
    removeTree(root);
    root = nullptr;
}

void BinarySearchTree::removeTree(Node* currentNode){
    if(currentNode != nullptr){
        removeTree(currentNode->leftChild);
        removeTree(currentNode->rightChild);

        delete currentNode;
        currentNode = nullptr;
    }
}

bool BinarySearchTree::isEmpty() const{
    return(root == nullptr);
}

void BinarySearchTree::insert(const Student& student){
    Node* newNode = new Node;
    newNode->student = student;
    newNode->rightChild = nullptr;
    newNode->leftChild = nullptr;
    if(root == nullptr){
        root = newNode;
        return;
    } 

    Node* temp = root;

    while(true){
        if(student.getId() < temp->student.getId()){
            if(temp->leftChild == nullptr){
                temp->leftChild = newNode;
                return;
            }
            temp = temp->leftChild;
        } else if(student.getId() > temp->student.getId()){
            if(temp->rightChild == nullptr){
                temp->rightChild = newNode;
                return;
            }
            temp = temp->rightChild;
        } else{
            delete newNode;
            return;
        }
    }
}
void BinarySearchTree::remove(const Student& student){
    removeSearch(student, root);
}

void BinarySearchTree::getInOrderSuccessor(Student& nextStudent, Node* temp){
    Node* successor = temp->rightChild;

    while(successor->leftChild != nullptr){
        successor = successor->leftChild;
    }
    nextStudent = successor->student;
}


void BinarySearchTree::removeSearch(const Student& student, Node*& currentNode){
    if(currentNode == nullptr){
        return;
    }

    if(student.getId() < currentNode->student.getId()){
        removeSearch(student, currentNode->leftChild);
    } else if (student.getId() > currentNode->student.getId()){
        removeSearch(student, currentNode->rightChild);
    } else {
        removeNode(currentNode);
    }
}

void BinarySearchTree::removeNode(Node*& currentNode){
    Node* temp = currentNode;
    if(currentNode->leftChild == nullptr){
        currentNode = currentNode->rightChild;
        delete temp;
    } else if(currentNode->rightChild == nullptr){
        currentNode = currentNode->leftChild;
        delete temp;
    } else{
        Student nextStudent;
        getInOrderSuccessor(nextStudent, currentNode);
        currentNode->student = nextStudent;
        removeSearch(nextStudent, currentNode->rightChild); 
    }
}

bool BinarySearchTree::search(int id, Student& result) const{
    Node* currentNode = root;

    while(currentNode != nullptr){
        if(id < currentNode->student.getId()){
            currentNode = currentNode->leftChild;
        } else if(id > currentNode->student.getId()){
            currentNode = currentNode->rightChild;
        } else{
            result = currentNode->student;
            return true;
        }
    }

    return false;
}

bool BinarySearchTree::updateStudentName(int id, const std::string& newName){
    Node* currentNode = root;

    while(currentNode != nullptr){
        if(id < currentNode->student.getId()){
            currentNode = currentNode->leftChild;
        } else if (id > currentNode->student.getId()){
            currentNode = currentNode->rightChild;
        } else{
            currentNode->student.setName(newName);
            return true;
        }
    }

    return false;
}

void BinarySearchTree::printInOrder() const{
    printInOrder(root);
}


void BinarySearchTree::printPreOrder() const{
    printPreOrder(root);
}


void BinarySearchTree::printPostOrder() const{
    printPostOrder(root);
}

void BinarySearchTree::printPreOrder(Node* currentNode) const{
    if(currentNode != nullptr){
        std::cout << currentNode->student.getName() << ": ";
        std::cout << currentNode->student.getId() << std::endl;
        
        printPreOrder(currentNode->leftChild);
        printPreOrder(currentNode->rightChild);
    }

}
void BinarySearchTree::printInOrder(Node* currentNode) const{
    if(currentNode != nullptr){
        printInOrder(currentNode->leftChild);

        std::cout << currentNode->student.getName() << ": ";
        std::cout << currentNode->student.getId() << std::endl;

        printInOrder(currentNode->rightChild);
    }
}
void BinarySearchTree::printPostOrder(Node* currentNode) const{
    if(currentNode != nullptr){
        printPostOrder(currentNode->leftChild);
        printPostOrder(currentNode->rightChild);

        std::cout << currentNode->student.getName() << ": ";
        std::cout << currentNode->student.getId() << std::endl;
    }
}