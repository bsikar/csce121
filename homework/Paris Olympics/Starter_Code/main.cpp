/******************************************************************************

File: main.cpp
Author: Prof. Lupoli & Andrew Nemec
Date: 2/16/2021
Section:
E-mail: slupoli@tamu.edu
Description:
This file contains C++  code that will simulate data collected from a track
event with 9 lanes. The code will sort the order, then display the results

Updates
Author: J. Michael Moore & Paul Taele
Author: J. Michael Moore

Input information format
<Time (double)> <Abbreviated Country (String)> <Uniform number (int)> <Lastname
(String)> 32.7 USA 12 Moore 36.5 RUS 35 Polsley 45.8 ENG 73 Teale 52.34 CHN 14
Nemec 76.45 ITY 23 Lupoli

*******************************************************************************/

#include "parallel_tracks.h"
#include <iostream>

using std::cout;
using std::endl;
using std::string;

int main() {
  // prepare the data
  double times[SIZE];
  prep_double_array(times);

  string country_codes[SIZE];
  prep_string_array(country_codes);

  unsigned int jerseys[SIZE];
  prep_unsigned_int_array(jerseys);

  string lastnames[SIZE];
  prep_string_array(lastnames);

  // get the data
  bool result = get_runner_data(times, country_codes, jerseys, lastnames);

  // validate the data
  if (!result) {
    cout << "Bad input" << endl;
    return 1;
  }

  unsigned int order[SIZE];
  prep_unsigned_int_array(order);
  get_ranking(times, order);

  // display the data
  print_results(times, country_codes, lastnames, order);

  // this is not required in C++ but many people still explitly add it
  return 0;
}
