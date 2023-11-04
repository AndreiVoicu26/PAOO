#include <iostream>
#include "Student.hpp"
#include "../../Subject/Subject.hpp"
#include "../Person/Person.cpp"
using namespace SubjectNamespace;
using namespace PeopleNamespace;

Student::Student(const std::string &firstName, const std::string &lastName, int age)
    : Person(firstName, lastName, age)
{
    this->subjects = new std::vector<Subject>();
}

Student::Student(const Student &copy)
{
    std::cout << "Copy Constructor called" << std::endl;
    firstName = copy.firstName;
    lastName = copy.lastName;
    age = copy.age;
    subjects = new std::vector<Subject>(*copy.subjects);
}

Student::Student(Student &&source)
{
    std::cout << "Move Constructor called" << std::endl;
    firstName = std::move(source.firstName);
    lastName = std::move(source.lastName);
    age = source.age;
    subjects = source.subjects;
    source.subjects = nullptr;
}

Student &Student::operator=(const Student &ref)
{
    std::cout << "Assignment Operator called" << std::endl;
    if (this == &ref)
    {
        return *this;
    }

    subjects = new std::vector<Subject>(*ref.subjects);

    return *this;
}

void Student::addSubject(const Subject &subject)
{
    subjects->push_back(subject);
}

const std::vector<Subject> &Student::getSubjects() const
{
    return *subjects;
}

void Student::display() const
{
    std::cout << "Student:" << std::endl;
    std::cout << "First Name: " << firstName << std::endl;
    std::cout << "Last Name: " << lastName << std::endl;
    std::cout << "Age: " << age << std::endl;

    if (!subjects->empty())
    {
        std::cout << "Learns: ";
        for (const Subject &subject : *subjects)
        {
            std::cout << subject.getName() << " ";
        }
        std::cout << std::endl;
    }
    else
    {
        std::cout << "No subjects assigned" << std::endl;
    }
}

Student::~Student()
{
    delete subjects;
}
