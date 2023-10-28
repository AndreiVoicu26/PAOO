#include <iostream>
#include <string>
#include "Student/Student.hpp"
#include "Subject/Subject.hpp"

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
}
