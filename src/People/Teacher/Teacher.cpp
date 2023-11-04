#include <iostream>
#include "Teacher.hpp"
#include "../../Subject/Subject.hpp"
#include "../Person/Person.hpp"
using namespace SubjectNamespace;
using namespace PeopleNamespace;

Teacher::Teacher(const std::string &firstName, const std::string &lastName, int age, Subject *subject)
    : Person(firstName, lastName, age)
{
    this->subject = new Subject(subject->getName());
}

Teacher::Teacher(const Teacher &copy)
{
    std::cout << "Copy Constructor called" << std::endl;
    firstName = copy.firstName;
    lastName = copy.lastName;
    age = copy.age;
    subject = copy.subject;
}

Teacher::Teacher(Teacher &&source)
{
    std::cout << "Move Constructor called" << std::endl;
    firstName = std::move(source.firstName);
    lastName = std::move(source.lastName);
    age = source.age;
    subject = source.subject;
    source.subject = nullptr;
}

Teacher &Teacher::operator=(const Teacher &ref)
{
    std::cout << "Assignment Operator called" << std::endl;
    if (this == &ref)
    {
        return *this;
    }

    subject = ref.subject;

    return *this;
}

void Teacher::setSubject(Subject *subject)
{
    this->subject = subject;
}

const Subject *Teacher::getSubject() const
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
        std::cout << "Teaches: " << subject->getName() << std::endl;
    }
    else
    {
        std::cout << "No subject assigned" << std::endl;
    }
}

Teacher::~Teacher()
{
    delete subject;
}
