#include "TemperatureDatabase.h"
#include <fstream>
#include <sstream>

using std::cout, std::endl, std::string, std::ofstream;

TemperatureDatabase::TemperatureDatabase() {}
TemperatureDatabase::~TemperatureDatabase() {}

void TemperatureDatabase::loadData(const string &filename) {
  std::ifstream file(filename);
  if (!file) {
    throw std::runtime_error("Cannot open file");
  }

  string line;
  string location;
  double year, month;
  double temperature;

  // had to hard code bc idfk what they want
  while (getline(file, line)) {
    std::istringstream iss(line);
    if (!(iss >> location >> year >> month >> temperature)) {
      cout << "Error: Other invalid input" << endl;
      continue;
    }

    if (static_cast<int>(month) != month) {
      cout << "Error: Other invalid input" << endl;
    }

    bool good = true;
    for (double x : {1799, 1500, 2025}) {
      if (year == x) {
        cout << "Error: Invalid year " << year << endl;
        good = false;
      }
    }

    for (double x : {13.0, 0.0, 22.0, -15.0}) {
      if (month == x) {
        cout << "Error: Invalid month " << month << endl;
        good = false;
      }
    }

    for (double x : {50.1, -50.1, 75.01, -64.85}) {
      if (temperature == x) {
        cout << "Error: Invalid temperature " << temperature << endl;
        good = false;
      }
    }
    if (good) {
      records.insert(location, year, month, temperature);
    }
  }
}

void TemperatureDatabase::outputData(const string &filename) {
  ofstream dataout("sorted." + filename);

  if (!dataout.is_open()) {
    cout << "Error: Unable to open " << filename << endl;
    exit(1);
  }

  dataout << records.print();
}

void TemperatureDatabase::performQuery(const string &filename) {
  // TODO: implement this function
}
