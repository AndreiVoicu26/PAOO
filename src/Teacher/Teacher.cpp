#include <iostream>
#include "Teacher.hpp"
#include "../Subject/Subject.hpp"
#include "../Person/Person.hpp"
using namespace SubjectNamespace;
using namespace PeopleNamespace;

Teacher::Teacher(const std::string &firstName, const std::string &lastName, int age, const std::shared_ptr<Subject> &subject)
    : Person(firstName, lastName, age), subject(subject)
{
}

Teacher::Teacher(const Teacher &copy)
{
    firstName = copy.firstName;
    lastName = copy.lastName;
    age = copy.age;
    this->subject = std::make_shared<Subject>(copy.subject->getName());
}

Teacher::Teacher(Teacher &&source)
{
    firstName = std::move(source.firstName);
    lastName = std::move(source.lastName);
    age = source.age;
    this->subject = (std::move(source.subject));
    source.subject = nullptr;
}

Teacher &Teacher::operator=(const Teacher &ref)
{
    if (this == &ref)
    {
        return *this;
    }

    subject = std::make_shared<Subject>(ref.subject->getName());

    return *this;
}

void Teacher::setSubject(Subject *subject)
{
    this->subject = std::make_shared<Subject>(subject->getName());
}

const std::shared_ptr<Subject> Teacher::getSubject() const
{
    return subject;
}

void Teacher::display() const
{
    std::cout << "Teacher:" << std::endl;
    std::cout << "First Name: " << firstName << std::endl;
    std::cout << "Last Name: " << lastName << std::endl;
    std::cout << "Age: " << age << std::endl;

    if (subject)
    {
        std::cout << "Teaches: " << subject->getName() << std::endl
                  << std::endl;
    }
    else
    {
        std::cout << "No subject assigned" << std::endl;
    }
}
