#include "parallel_tracks.h"
#include <iomanip>
#include <iostream>
#include <string>

using std::string;

using std::cin;

//-------------------------------------------------------
// Name: get_time
// PreCondition:  the time array and the index of the array
// PostCondition: the time array is filled with a new time at the index
//---------------------------------------------------------
bool get_time(double *arr, unsigned int idx) {
  double time;
  cin >> time;
  // check if cin failed
  if (cin.fail()) {
    return false;
  }
  // time condition
  if (time < 0) {
    return false;
  }

  arr[idx] = time;
  return true;
}

//-------------------------------------------------------
// Name: get_country
// PreCondition:  the country array and the index of the array
// PostCondition: the country array is filled with a new country at the index
//---------------------------------------------------------
bool get_country(string *arr, unsigned int idx) {
  string country;
  cin >> country;
  // trim code
  country = trim(country);
  // XXX: Debug
  // std::cout << "Country: " << country << std::endl;
  // check if cin failed
  if (cin.fail()) {
    return false;
  }

  // check the length
  if (country.length() != 3) {
    return false;
  }

  // check the characters
  // they must be upper case letters
  for (char c : country) {
    if (c < 'A' || c > 'Z') {
      return false;
    }
  }

  arr[idx] = country;
  return true;
}

//-------------------------------------------------------
// Name: get_jersey
// PreCondition:  the jersey array and the index of the array
// PostCondition: the jersey array is filled with a new jersey at the index
//---------------------------------------------------------
bool get_jersey(unsigned int *arr, unsigned int idx) {
  unsigned int jersey;
  cin >> jersey;
  // check if cin failed
  if (cin.fail()) {
    return false;
  }

  arr[idx] = jersey;
  return jersey < 100;
}

//-------------------------------------------------------
// Name: get_lastname
// PreCondition:  the lastname array and the index of the array
// PostCondition: the lastname array is filled with a new lastname at the index
//---------------------------------------------------------
bool get_lastname(string *arr, unsigned int idx) {
  string lastname;
  cin >> lastname;
  // trim the name
  lastname = trim(lastname);
  // XXX: Debug
  // std::cout << "lastname: " << lastname << std::endl;
  // check if cin failed
  if (cin.fail()) {
    return false;
  }

  // length has to be at least 1
  if (lastname.length() <= 1) {
    return false;
  }

  // has to have alphabetical characters
  for (char c : lastname) {
    if ((c < 'A' || c > 'Z') && (c < 'a' || c > 'z')) {
      return false;
    }
  }

  arr[idx] = lastname;
  return true;
}

//-------------------------------------------------------
// Name: get_runner_data
// PreCondition:  the prepped parallel arrays
// PostCondition: all arrays contain data from standard in
//---------------------------------------------------------
bool get_runner_data(double timeArray[], std::string countryArray[],
                     unsigned int numberArray[], std::string lastnameArray[]) {
  for (unsigned int i = 0; i < SIZE; i++) {
    // get time
    if (!get_time(timeArray, i)) {
      return false;
    }

    // get country
    if (!get_country(countryArray, i)) {
      return false;
    }

    // get jersey
    if (!get_jersey(numberArray, i)) {
      return false;
    }

    // get lastname
    if (!get_lastname(lastnameArray, i)) {
      return false;
    }
  }
  return true;
}

//-------------------------------------------------------
// Name: prep_double_array
// PreCondition:  an array of doubles is passed in
// PostCondition: data in the array is 'zeroed' out
//---------------------------------------------------------
void prep_double_array(double ary[])
// making sure all values within the array are set to 0.0;
{
  for (unsigned int i = 0; i < SIZE; i++) {
    ary[i] = 0.0;
  }
}

//-------------------------------------------------------
// Name: prep_unsigned_int_array
// PreCondition:  an array of unsigned ints is passed in
// PostCondition: data in the array is 'zeroed' out
//---------------------------------------------------------
void prep_unsigned_int_array(unsigned int ary[])
// making sure all values within the array are set to 0;
{
  for (unsigned int i = 0; i < SIZE; i++) {
    ary[i] = 0;
  }
}

//-------------------------------------------------------
// Name: prep_string_array
// PreCondition:  an array of strings is passed in
// PostCondition: each element in the array is set to "N/A"
//---------------------------------------------------------
void prep_string_array(std::string ary[])
// making sure all values within the array are set to "N/A";
{
  for (unsigned int i = 0; i < SIZE; i++) {
    ary[i] = "N/A";
  }
}

//-------------------------------------------------------
// Name: get_ranking
// PreCondition:  just the time array is passed in, and has valid data
// PostCondition: after a very inefficient nested loop to determine the
// placements and places the ranks in a new array. That new array is returned
//---------------------------------------------------------
void get_ranking(const double timeArray[], unsigned int rankArray[]) {
  // loop through the time array
  for (unsigned int i = 0; i < SIZE; i++) {
    // set the rank to 1
    rankArray[i] = 1;
    // loop through the time array again
    for (unsigned int j = 0; j < SIZE; j++) {
      // if the time is less than the current time
      if (timeArray[j] < timeArray[i]) {
        // increment the rank
        rankArray[i]++;
      }
    }
  }
}

//-------------------------------------------------------
// Name: print_results
// PreCondition:  all parallel arrays are passed in and have valid data
// PostCondition: after a very inefficient nested loop to determine the ranks
// it then displays them along with a delta in time from the start
//---------------------------------------------------------
void print_results(const double timeArray[], const std::string countryArray[],
                   const std::string lastnameArray[],
                   const unsigned int rankArray[]) {

  std::cout << "Final results!!";
  std::cout << std::setprecision(2) << std::showpoint << std::fixed
            << std::endl;
  double best_time = 0.0;

  // print the results, based on rank, but measure the time difference_type
  for (unsigned int j = 1; j <= SIZE; j++) {

    // go thru each array, find who places in "i" spot
    for (unsigned int i = 0; i < SIZE; i++) {
      if (rankArray[i] ==
          1) // has to be a better way, but need the starting time
      {
        best_time = timeArray[i];
      }

      if (rankArray[i] == j) // then display this person's data
      {
        // this needs precision display
        std::cout << "[" << j << "]  " << timeArray[i] << " " << std::setw(15)
                  << std::left << lastnameArray[i] << "\t"
                  << "(" << countryArray[i] << ")  +"
                  << (timeArray[i] - best_time) << std::endl;
      }
    }
  }
}

std::string trim(std::string ret) {
  // remove whitespace from the beginning
  while (!ret.empty() && isspace(ret.at(0))) {
    ret.erase(0, 1);
  }

  // remove whitespace from the end
  //  Note: last index is (.size() - 1) due to 0 based indexing
  while (!ret.empty() && isspace(ret.at(ret.size() - 1))) {
    ret.erase(ret.size() - 1, 1);
  }

  return ret;
}
