#ifndef PERSON_HPP
#define PERSON_HPP
#include <string>
#include <iostream>

namespace PeopleNamespace
{
    class Person
    {
    protected:
        std::string firstName;
        std::string lastName;
        int age;

    public:
        Person();
        Person(const std::string &firstName, const std::string &lastName, int age);

        void setFirstName(const std::string &firstName);
        void setLastName(const std::string &lastName);
        void setAge(int age);

        const std::string &getFirstName() const;
        const std::string &getLastName() const;
        int getAge() const;

        virtual void display() const = 0;
    };
}

#endif