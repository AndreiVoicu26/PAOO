#include <iostream>
#include <string>
#include "People/Student/Student.hpp"
#include "People/Teacher/Teacher.hpp"
#include "Subject/Subject.hpp"
using namespace PeopleNamespace;
using namespace SubjectNamespace;

int main()
{
    Student student("Andrei", "Voicu", 21);
    student.addSubject(Subject("Math"));
    student.addSubject(Subject("Physics"));
    student.display();

    Student student2(student);
    student2.display();

    Student student3("Ion", "Popescu", 22);
    student3 = student2;
    student3.display();

    Student tempStudent("Ana", "Maria", 25);
    tempStudent.addSubject(Subject("History"));
    Student student4(std::move(tempStudent));
    student4.display();

    student4.setAge(30);
    student4.display();

    Subject *subject = new Subject("Math");
    Teacher teacher("Cosmin", "Ionescu", 43, subject);
    teacher.display();
}
