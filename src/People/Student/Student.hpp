#ifndef STUDENT_HPP
#define STUDENT_HPP
#include <string>
#include <vector>
#include "../../Subject/Subject.hpp"
#include "../Person/Person.hpp"
using namespace SubjectNamespace;

namespace PeopleNamespace
{
    class Student : public Person
    {
    private:
        std::vector<Subject> *subjects;

    public:
        Student(const std::string &firstName, const std::string &lastName, int age);
        Student(const Student &copy);
        Student(Student &&source);
        Student &operator=(const Student &ref);

        void addSubject(const Subject &subject);
        const std::vector<Subject> &getSubjects() const;

        void display() const;

        ~Student();
    };
}

#endif