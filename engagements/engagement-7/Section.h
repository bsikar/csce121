#ifndef SECTION_H
#define SECTION_H

#include "Course.h"
#include "Student.h"
#include <vector>

class Section {
  int id;
  std::string time;
  std::vector<Student> studentList;
  Course course_info;

public:
  int getID() const;
  void setId(int id);
  std::string getTime() const;
  void setTime(std::string time);
  std::vector<Student> getStudentList() const;
  void setStudentList(std::vector<Student> studentList);
  void set_course_info(Course course_info);
  Course get_course_info();
};

#endif
