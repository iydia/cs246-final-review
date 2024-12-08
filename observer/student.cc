#include "student.h"

using namespace std;

Student::Student(shared_ptr<CS246>course, string name, float knowledge) : course{course}, name{name}, knowledge{knowledge} {
    /* ----- FILL IN ----- */  
    course->add(this); // from the shared_ptr course, add the student object
    cout << name << " is now enrolled!" << endl;
}

Student::~Student() {
    /* ----- FILL IN ----- */
    course->drop(this);
}

void Student::study() { knowledge = ((knowledge + 0.1) >= 1)? 1 : (knowledge + 0.1); }

void Student::doHomework() {
    Assignment homework = course->getAssignment();
    grade += (homework.getWeight() * knowledge * 100);
    cout << name << " completed " << homework.getName() << "! Total grade: " << grade << endl;
}

string Student::getName() const { return name; }

float Student::getKnowledge() const { return knowledge; }
