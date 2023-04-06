#ifndef COURSE_H
#define COURSE_H

#include <string>

class Course {
  unsigned short CRN;
  std::string duration;
  bool status;
  unsigned short max_seats;
  unsigned short actual_seats;
  unsigned short remaining_seats;

public:
  unsigned short getCRN();
  void setCRN(unsigned short CRN);
  std::string getDuration();
  void setDuration(std::string duration);
  bool getStatus();
  void setStatus(bool status);
  unsigned short getMaxSeats();
  void setMaxSeats(unsigned short max_seats);
  unsigned short getActualSeats();
  void setActualSeats(unsigned short actual_seats);
  unsigned short getRemainingSeats();
  void setRemainingSeats(unsigned short remaining_seats);
};

#endif
