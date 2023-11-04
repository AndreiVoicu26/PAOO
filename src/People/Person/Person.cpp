#include "Person.hpp"
using namespace PeopleNamespace;

Person::Person() : firstName(""), lastName(""), age(0) {}

Person::Person(const std::string &firstName, const std::string &lastName, int age) : firstName(firstName), lastName(lastName), age(age) {}

void Person::setFirstName(const std::string &firstName)
{
    this->firstName = firstName;
}

void Person::setLastName(const std::string &lastName)
{
    this->lastName = lastName;
}

void Person::setAge(int age)
{
    this->age = age;
}

const std::string &Person::getFirstName() const
{
    return firstName;
}

const std::string &Person::getLastName() const
{
    return lastName;
}

int Person::getAge() const
{
    return age;
}