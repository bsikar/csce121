#ifndef PARALLEL_TRACKS_H
#define PARALLEL_TRACKS_H

#include <string>

const unsigned int SIZE = 9; // lines in the data

//-------------------------------------------------------
// Name: get_time
// PreCondition:  the time array and the index of the array
// PostCondition: the time array is filled with a new time at the index
//---------------------------------------------------------
bool get_time(double *arr, unsigned int idx);

//-------------------------------------------------------
// Name: get_country
// PreCondition:  the country array and the index of the array
// PostCondition: the country array is filled with a new country at the index
//---------------------------------------------------------
bool get_country(std::string *arr, unsigned int idx);

//-------------------------------------------------------
// Name: get_jersey
// PreCondition:  the jersey array and the index of the array
// PostCondition: the jersey array is filled with a new jersey at the index
//---------------------------------------------------------
bool get_jersey(unsigned int *arr, unsigned int idx);

//-------------------------------------------------------
// Name: get_lastname
// PreCondition:  the lastname array and the index of the array
// PostCondition: the lastname array is filled with a new lastname at the index
//---------------------------------------------------------
bool get_lastname(std::string *arr, unsigned int idx);

//-------------------------------------------------------
// Name: get_runner_data
// PreCondition:  the prepped parallel arrays
// PostCondition: all arrays contain data gotten from standard in
//---------------------------------------------------------
bool get_runner_data(double timeArray[], std::string countryArray[],
                     unsigned int numberArray[], std::string lastnameArray[]);

//-------------------------------------------------------
// Name: prep_double_array
// PreCondition:  a double arrays is pass in
// PostCondition: data in the array is 'zeroed' out
//---------------------------------------------------------
void prep_double_array(double ary[]);

//-------------------------------------------------------
// Name: prep_double_array
// PreCondition:  a double arrays is pass in
// PostCondition: data in the array is 'zeroed' out
//---------------------------------------------------------
void prep_unsigned_int_array(unsigned int ary[]);

//-------------------------------------------------------
// Name: prep_string_array
// PreCondition:  a string arrays is pass in
// PostCondition: data in the array is "N/A" out to determine if
// a value has changed
//---------------------------------------------------------
void prep_string_array(std::string ary[]);

//-------------------------------------------------------
// Name: get_ranking
// PreCondition:  just the time array is passed in, and has valid data
// PostCondition: after a very inefficient nested loop to determine the
// placements and places the ranks in a new array. That new array is returned
//---------------------------------------------------------
void get_ranking(const double timeArray[], unsigned int rankArray[]);

//-------------------------------------------------------
// Name: print_results
// PreCondition:  almost all parallel arrays are passed in and have valid data
// PostCondition: after a very inefficient nested loop to determine the ranks
// it then displays then along with a delta in time from the start
//---------------------------------------------------------
void print_results(const double timeArray[], const std::string countryArray[],
                   const std::string lastnameArray[],
                   const unsigned int rankArray[]);

//-------------------------------------------------------
// Name: trim
// PreCondition:  string
// PostCondition: returns string with whitespace removed from beginning and end
//---------------------------------------------------------
std::string trim(std::string);

#endif
