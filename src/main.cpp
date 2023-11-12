#include <iostream>
#include <string>
#include <vector>
#include "Student/Student.hpp"
#include "Teacher/Teacher.hpp"
#include "Subject/Subject.hpp"
#include "Department/Department.cpp"
using namespace PeopleNamespace;
using namespace SubjectNamespace;
using namespace DepartmentNamespace;

int main()
{
    Student student("Andrei", "Voicu", 21);
    student.addSubject(Subject("Math"), 9);
    student.addSubject(Subject("Physics"), 8.5);
    student.display();

    Student student2(student);
    student2.display();

    Student student3("Ion", "Popescu", 22);
    student3 = student2;
    student3.display();

    Student tempStudent("Ana", "Maria", 25);
    tempStudent.addSubject(Subject("History"), 7);
    Student student4(std::move(tempStudent));
    student4.display();

    student4.setAge(30);
    student4.display();

    Subject subject("Operating Systems");
    Teacher teacher("Cosmin", "Ionescu", 43, std::make_shared<Subject>(subject));
    teacher.display();
    Teacher teacher2("Mihai", "Dragomir", 56, std::make_shared<Subject>(subject));
    teacher2.display();

    auto students = std::make_unique<std::vector<Student>>();
    students->push_back(student);
    students->push_back(student3);
    std::cout << "Students:" << std::endl;
    displayItems<Student>(*students);

    Department<Student> computerScienceStudents("Computer Science Students", std::move(students));
    computerScienceStudents.addParticipant(student4);
    computerScienceStudents.displayParticipants();

    auto teachers = std::make_unique<std::vector<Teacher>>();
    teachers->push_back(teacher);
    teachers->push_back(teacher2);
    std::cout << "Teachers:" << std::endl;
    displayItems<Teacher>(*teachers);

    Department<Teacher> computerScienceTeachers("Computer Science Students", std::move(teachers));
    computerScienceTeachers.displayParticipants();
}
