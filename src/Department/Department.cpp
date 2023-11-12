#include "Department.hpp"
using namespace DepartmentNamespace;

template <typename PersonType>
Department<PersonType>::Department(const std::string &departmentName, std::unique_ptr<std::vector<PersonType>> initialParticipants)
    : name(departmentName), participants(std::move(initialParticipants))
{
}

template <typename PersonType>
void Department<PersonType>::addParticipant(PersonType &participant)
{
    participants->push_back(participant);
}

template <typename PersonType>
void Department<PersonType>::displayParticipants() const
{
    std::cout << "Participants in " << name << " department: " << std::endl;
    displayItems(*participants);
}
