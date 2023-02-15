#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
  string yourUsername;
  string yourDomain;

  cin >> yourUsername;
  cin >> yourDomain;

  try {
    if (yourUsername.length() < 3 || yourUsername.length() > 6) {
      throw runtime_error("User name's length must be between 3 and 6");
    }

    if (yourDomain[0] != '@') {
      throw runtime_error("Domain must start with '@'");
    }

    cout << "Sending email to " << yourUsername << yourDomain << endl;
  } catch (runtime_error &excpt) {
    cout << "Error: " << excpt.what() << endl;
  }

  return 0;
}
