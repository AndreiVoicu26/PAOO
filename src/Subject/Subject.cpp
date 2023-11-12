#include "Subject.hpp"
using namespace SubjectNamespace;

Subject::Subject(const std::string &name) : name(name){};

void Subject::setName(const std::string &name)
{
    this->name = name;
}

const std::string &Subject::getName() const
{
    return name;
}

bool Subject::operator<(const Subject &other) const
{
    return name < other.name;
}