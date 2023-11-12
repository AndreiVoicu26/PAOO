#include <iostream>
#include "Student.hpp"
#include "../Subject/Subject.hpp"
#include "../Person/Person.cpp"
using namespace SubjectNamespace;
using namespace PeopleNamespace;

Student::Student(const std::string &firstName, const std::string &lastName, int age)
    : Person(firstName, lastName, age)
{
    this->subjects = new std::map<Subject, double>();
}

Student::Student(const Student &copy)
{
    firstName = copy.firstName;
    lastName = copy.lastName;
    age = copy.age;
    subjects = new std::map<Subject, double>(*copy.subjects);
}

Student::Student(Student &&source)
{
    firstName = std::move(source.firstName);
    lastName = std::move(source.lastName);
    age = source.age;
    subjects = source.subjects;
    source.subjects = nullptr;
}

Student &Student::operator=(const Student &ref)
{
    if (this == &ref)
    {
        return *this;
    }

    subjects = new std::map<Subject, double>(*ref.subjects);

    return *this;
}

void Student::addSubject(const Subject &subject, double grade)
{
    auto result = subjects->insert({subject, grade});

    if (!result.second)
    {
        result.first->second = grade;
    }
}

const std::map<Subject, double> &Student::getSubjects() const
{
    return *subjects;
}

double Student::getGrade(const Subject &subject) const
{
    auto it = subjects->find(subject);
    return (it != subjects->end()) ? it->second : -1;
}

void Student::display() const
{
    std::cout << "Student:" << std::endl;
    std::cout << "First Name: " << firstName << std::endl;
    std::cout << "Last Name: " << lastName << std::endl;
    std::cout << "Age: " << age << std::endl;

    if (!subjects->empty())
    {
        std::cout << "Subjects with Grades:" << std::endl;
        for (const auto &entry : *subjects)
        {
            const Subject &subject = entry.first;
            double grade = entry.second;
            std::cout << subject.getName() << ": " << grade << std::endl;
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
