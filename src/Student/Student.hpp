#ifndef STUDENT_HPP
#define STUDENT_HPP
#include <string>
#include <map>
#include "../Subject/Subject.hpp"
#include "../Person/Person.hpp"
using namespace SubjectNamespace;

namespace PeopleNamespace
{
    class Student : public Person
    {
    private:
        std::map<Subject, double> *subjects;

    public:
        Student(const std::string &firstName, const std::string &lastName, int age);
        Student(const Student &copy);
        Student(Student &&source);
        Student &operator=(const Student &ref);

        void addSubject(const Subject &subject, double grade);
        const std::map<Subject, double> &getSubjects() const;
        double getGrade(const Subject &subject) const;

        void display() const;

        ~Student();
    };
}

#endif