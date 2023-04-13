#include "Database.h"

using std::string, std::vector;

// TODO: implement constructor using member initializer list
Database::Database() : stateParkList(), camperList() {}

Database::~Database() {
  for (unsigned int i = 0; i < stateParkList.size(); ++i) {
    delete stateParkList.at(i);
  }

  for (unsigned int i = 0; i < camperList.size(); ++i) {
    delete camperList.at(i);
  }
}

void Database::addStatePark(string parkName, double entranceFee,
                            double trailMiles) {
  INFO(parkName)
  INFO(entranceFee)
  INFO(trailMiles)

  StatePark *park = new StatePark(parkName, entranceFee, trailMiles);
  stateParkList.push_back(park);

  return;
}

void Database::addPassport(string camperName, bool isJuniorPassport) {
  INFO(camperName)
  INFO(isJuniorPassport)

  Passport *passport = new Passport(camperName, isJuniorPassport);
  camperList.push_back(passport);

  return;
}

void Database::addParkToPassport(string camperName, string parkName) {
  INFO(camperName)
  INFO(parkName)

  for (unsigned int i = 0; i < camperList.size(); ++i) {
    if (camperList.at(i)->getCamperName() == camperName) {
      for (unsigned int j = 0; j < stateParkList.size(); ++j) {
        if (stateParkList.at(j)->getParkName() == parkName) {
          camperList.at(i)->addParkVisited(stateParkList.at(j));
        }
      }
    }
  }

  return;
}

vector<string> Database::getParksInRevenueRange(double lowerBound,
                                                double upperBound) {
  INFO(lowerBound)
  INFO(upperBound)

  // TODO: (optional) implement function

  return {};
}

vector<string> Database::getHikersAtLeastLevel(int level) {
  INFO(level)

  // TODO: (optional) implement function

  return {};
}
