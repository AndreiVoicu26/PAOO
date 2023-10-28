#include "Subject.hpp"

Subject::Subject(const std::string &name) : name(name){};

void Subject::setName(const std::string &name)
{
    this->name = name;
}

const std::string &Subject::getName() const
{
    return name;
}