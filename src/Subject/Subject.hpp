#ifndef SUBJECT_HPP
#define SUBJECT_HPP
#include <string>

class Subject
{
private:
    std::string name;

public:
    Subject(const std::string &name);

    void setName(const std::string &name);

    const std::string &getName() const;
};

#endif