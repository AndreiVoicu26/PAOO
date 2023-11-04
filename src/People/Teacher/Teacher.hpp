#ifndef TEACHER_HPP
#define TEACHER_HPP
#include <string>
#include <vector>
#include "../../Subject/Subject.hpp"
#include "../Person/Person.hpp"
using namespace SubjectNamespace;

namespace PeopleNamespace
{
    class Teacher : public Person
    {
    private:
        Subject *subject;

    public:
        Teacher(const std::string &firstName, const std::string &lastName, int age, Subject *subject);
        Teacher(const Teacher &copy);
        Teacher(Teacher &&source);
        Teacher &operator=(const Teacher &ref);

        void setSubject(Subject *subject);
        const Subject *getSubject() const;

        void display() const;

        ~Teacher();
    };
}

#endif