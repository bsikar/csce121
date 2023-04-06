#include "Course.h"

unsigned short Course::getCRN() { return this->CRN; }

void Course::setCRN(unsigned short CRN) { this->CRN = CRN; }

std::string Course::getDuration() { return this->duration; }

void Course::setDuration(std::string duration) { this->duration = duration; }

bool Course::getStatus() { return this->status; }

void Course::setStatus(bool status) { this->status = status; }

unsigned short Course::getMaxSeats() { return this->max_seats; }

void Course::setMaxSeats(unsigned short max_seats) {
  this->max_seats = max_seats;
}

unsigned short Course::getActualSeats() { return this->actual_seats; }

void Course::setActualSeats(unsigned short actual_seats) {
  this->actual_seats = actual_seats;
}

unsigned short Course::getRemainingSeats() { return this->remaining_seats; }

void Course::setRemainingSeats(unsigned short remaining_seats) {
  this->remaining_seats = remaining_seats;
}
