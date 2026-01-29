#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "student.h"

struct Node{
    Student student;
    Node* leftChild;
    Node* rightChild;
};

class BinarySearchTree{
    private:
    Node* root;
    void printPreOrder(Node* currentNode) const;
    void printInOrder(Node* currentNode) const;
    void printPostOrder(Node* currentNode) const;

    public: 
    BinarySearchTree();
    ~BinarySearchTree();

    void removeTree(Node* currentNode);

    bool isEmpty() const;
    void insert(const Student& student);
    void remove(const Student& student);
    bool search(int id, Student& result) const;
    bool updateStudentName(int id, const std::string& newName);

    void removeSearch(const Student& student, Node*& currentNode);
    void removeNode(Node*& currentNode);
    void getInOrderSuccessor(Student& nextStudent, Node* temp);

    void printPreOrder() const;
    void printInOrder() const;
    void printPostOrder() const;

};

#endif