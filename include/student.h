#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student{
private:
    int id;
    std::string name;

public:
    Student();
    Student(int i, const std::string& n);
    
    std::string getName() const;
    int getId() const;

    void setName(const std::string& newName);
};

#endif