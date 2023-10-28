#ifndef STUDENT_HPP
#define STUDENT_HPP
#include <string>
#include <vector>
#include "../Subject/Subject.hpp"

class Student
{
private:
    std::string firstName;
    std::string lastName;
    int age;
    std::vector<Subject> *subjects;

public:
    Student(const std::string &firstName, const std::string &lastName, int age);
    Student(const Student &copy);
    Student &operator=(const Student &ref);

    void setFirstName(const std::string &firstName);
    void setLastName(const std::string &lastName);
    void setAge(int age);

    const std::string &getFirstName() const;
    const std::string &getLastName() const;
    int getAge() const;

    void addSubject(const Subject &subject);
    const std::vector<Subject> &getSubjects() const;

    void display() const;

    ~Student();
};

#endif