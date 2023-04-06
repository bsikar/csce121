#include <fstream>
#include <iostream>
#include <sstream>
using std::cin, std::cout, std::endl, std::string, std::getline, std::ifstream,
    std::istringstream;

int main() {
  string filename;
  cout << "Enter donation filename: ";
  cin >> filename;
  ifstream ifs(filename);
  if (!ifs.is_open()) {
    cout << "Failed to open file " << filename << "." << endl;
    return 1;
  }

  double maxTotalDonation = 0;
  int maxTotalCollector = 0;
  double maxSingleDonation = 0;
  int maxSingleDonationCollector = 0;
  int uniqueMaxCollector = 0;
  int uniqueMaxCount = 0;

  // read data
  string line;
  while (getline(ifs, line)) {
    istringstream iss(line);

    int count = 0;
    int collector;
    int uniqueCount = 0;
    double donation;
    double runningTotal = 0;
    iss >> collector;

    double uniqueValues[100];

    while (iss >> donation) {
      bool found = false;
      for (int i = 0; i < uniqueMaxCount; i++) {
        if (uniqueValues[i] == donation) {
          found = true;
          break;
        }
      }
      if (!found) {
        uniqueValues[uniqueCount++] = donation;
      }

      if (donation > maxSingleDonation) {
        maxSingleDonation = donation;
        maxSingleDonationCollector = collector;
      }

      runningTotal += donation;
      count += 1;
    }
    if (uniqueCount > uniqueMaxCount) {
      uniqueMaxCollector = collector;
      uniqueMaxCount = uniqueCount;
    }

    if (maxTotalDonation < runningTotal && count > 1) {
      maxTotalDonation = runningTotal;
      maxTotalCollector = collector;
    }
  }

  if (maxTotalDonation == 0) {
    cout << "No donations." << endl;
  } else {
    cout << "Highest donation total: " << maxTotalDonation << endl;
    cout << "-- collected by id: " << maxTotalCollector << endl;
    cout << "Highest single donation: " << maxSingleDonation << endl;
    cout << "-- collected by id: " << maxSingleDonationCollector << endl;
    cout << "Most unique donations: " << uniqueMaxCount << endl;
    cout << "-- collected by id: " << uniqueMaxCollector << endl;
  }
}
