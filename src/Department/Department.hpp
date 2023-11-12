#ifndef DEPARTMENT_HPP
#define DEPARTMENT_HPP
#include <iostream>
#include <string>
#include <vector>
#include <memory>

namespace DepartmentNamespace
{
    template <typename ItemType>
    void displayItems(const std::vector<ItemType> &items)
    {
        for (const auto &item : items)
        {
            std::cout << item.getFirstName() << " " << item.getLastName() << std::endl;
        }
        std::cout << std::endl;
    }

    template <typename PersonType>
    class Department
    {
    private:
        std::string name;
        std::unique_ptr<std::vector<PersonType>> participants;

    public:
        Department(const std::string &departmentName, std::unique_ptr<std::vector<PersonType>> initialParticipants);

        void addParticipant(PersonType &participant);
        void displayParticipants() const;
    };

}

#endif