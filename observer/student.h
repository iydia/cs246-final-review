#ifndef _STUDENT_H_
#define _STUDENT_H_
#include <iostream>
#include <string>
#include <memory>
#include "observer.h"
#include "cs246.h"

class Student: public Observer {
  shared_ptr<CS246> course;
  const string name;
  float knowledge; // 0 <= knowledge <= 1
  float grade;
 public:
  Student(shared_ptr<CS246>course, string name, float knowledge);
  void study();
  string getName() const;
  float getKnowledge() const;
  void doHomework() override;  // i.e. the notify() method
  ~Student();
};

#endif
