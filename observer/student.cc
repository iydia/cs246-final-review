#include "student.h"

using namespace std;

Student::Student(shared_ptr<CS246>course, string name, float knowledge) {
    /* ----- FILL IN ----- */  
}

Student::~Student() {
    /* ----- FILL IN ----- */
}

void Student::study() { knowledge = ((knowledge + 0.1) >= 1)? 1 : (knowledge + 0.1); }

void Student::doHomework() {
    Assignment homework = course->getAssignment();
    grade += (homework.getWeight() * knowledge * 100);
    cout << name << " completed " << homework.getName() << "! Total grade: " << grade << endl;
}

string Student::getName() const { return name; }

float Student::getKnowledge() const { return knowledge; }
