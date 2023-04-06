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

  // read data
  string line;
  while (getline(ifs, line)) {
    istringstream iss(line);

    int count = 0;
    int collector;
    double donation;
    double runningTotal = 0;
    iss >> collector;

    while (iss >> donation) {
      runningTotal += donation;
      count += 1;
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
  }
}
