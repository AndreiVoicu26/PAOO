#ifndef TEACHER_HPP
#define TEACHER_HPP
#include <string>
#include <memory>
#include "../Subject/Subject.hpp"
#include "../Person/Person.hpp"
using namespace SubjectNamespace;

namespace PeopleNamespace
{
    class Teacher : public Person
    {
    private:
        std::shared_ptr<Subject> subject;

    public:
        Teacher(const std::string &firstName, const std::string &lastName, int age, const std::shared_ptr<Subject> &subject);
        Teacher(const Teacher &copy);
        Teacher(Teacher &&source);
        Teacher &operator=(const Teacher &ref);

        void setSubject(Subject *subject);
        const std::shared_ptr<Subject> getSubject() const;

        void display() const;
    };
}

#endif