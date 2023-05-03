#include "TemperatureData.h"
using std::string;

TemperatureData::TemperatureData()
    : id(""), year(0), month(0), temperature(0.0) {}

TemperatureData::TemperatureData(string id, int year, int month,
                                 double temperature)
    : id(id), year(year), month(month), temperature(temperature) {}

TemperatureData::~TemperatureData() {}

bool TemperatureData::operator<(const TemperatureData &b) {
  if (this->id < b.id) {
    return true;
  } else if (this->id > b.id) {
    return false;
  }

  if (this->year < b.year) {
    return true;
  } else if (this->year > b.year) {
    return false;
  }

  return this->month < b.month;
}
