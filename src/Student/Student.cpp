#include <iostream>
#include "Student.hpp"
#include "../Subject/Subject.hpp"

Student::Student(const std::string &firstName, const std::string &lastName, int age)
    : firstName(firstName), lastName(lastName), age(age)
{
    subjects = new std::vector<Subject>();
}

Student::Student(const Student &copy)
{
    firstName = copy.firstName;
    lastName = copy.lastName;
    age = copy.age;
    subjects = new std::vector<Subject>(*copy.subjects);
}

Student &Student::operator=(const Student &ref)
{
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

void Student::setFirstName(const std::string &firstName)
{
    this->firstName = firstName;
}

void Student::setLastName(const std::string &lastName)
{
    this->lastName = lastName;
}

void Student::setAge(int age)
{
    this->age = age;
}

const std::string &Student::getFirstName() const
{
    return firstName;
}

const std::string &Student::getLastName() const
{
    return lastName;
}

int Student::getAge() const
{
    return age;
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
        std::cout << "Subjects: ";
        for (const Subject &subject : *subjects)
        {
            std::cout << subject.getName() << " ";
        }
        std::cout << std::endl;
    }
    else
    {
        std::cout << "No subjects" << std::endl;
    }
}

Student::~Student()
{
    delete subjects;
}
