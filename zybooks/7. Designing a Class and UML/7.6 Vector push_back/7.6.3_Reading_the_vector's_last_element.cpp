#include <iostream>
#include <vector>
using namespace std;

int main() {
   const int NUM_ELEMENTS = 3;
   vector<int> mpgTracker(NUM_ELEMENTS);
   int i;

   for (i = 0; i < mpgTracker.size(); ++i) {
      cin >> mpgTracker.at(i);
   }

   cout << "Last mpg reading: " << mpgTracker.at(mpgTracker.size() - 1) << endl;

   return 0;
}
