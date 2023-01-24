// These headers define some of the classes and functions we need
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

// These using declarations let us refer to things more simply
// e.g. instead of "std::cin" we can just write "cin"
using std::cin, std::cout, std::endl;
using std::string, std::getline;

// These methods are defined below the main function

// print instructions for inputting grades
void print_instructions();

// pretty print a summary of the grades
void print_results(double exam_average, double hw_average, double lw_average,
                   double reading, double engagement, double weighted_total,
                   char final_letter_grade);

// YOU ARE NOT EXPECTED TO UNDERSTAND THIS ONE... YET
// extract the category and score from the line
// and store the values in the provided variables
// if line := "exam 95", then category := "exam" and score := 95
// if the line is invalid, then category := "ignore"
void get_category_and_score(const string &line, string *category,
                            double *score);

// find the min since we cannot use std::min from algorithm
double min(double, double);

// find the max since we cannot use std::max from algorithm
double max(double, double);

int main() {
  print_instructions();

  // count variables for each category
  const int exam_count = 3;
  int lw_count = 0;
  int hw_count = 0;
  int reading_count = 0;
  int engagement_count = 0;

  // sum variables for each category
  double exam_sum = 0;
  double final_exam = 0;
  double hw_sum = 0;
  double lw_sum = 0;
  double reading_sum = 0;
  double engagement_sum = 0;
  double program_check_sum = 0;

  string line;
  // read one line from standard input (discards the ending newline character)
  getline(cin, line);
  // read lines until an empty line is read
  while (!line.empty()) {
    string category;
    double score;
    get_category_and_score(line, &category, &score);

    // process the grade entry
    if (category == "exam") {
      exam_sum += score;
    } else if (category == "final-exam") {
      final_exam = score;
      exam_sum += score;
    } else if (category == "hw") {
      hw_count += 1;
      hw_sum += score;
    } else if (category == "lw") {
      lw_count += 1;
      // lw_sum += (score == 0) ? -1 : 1;
      lw_sum += score;
    } else if (category == "reading") {
      reading_count += 1;
      reading_sum += score;
    } else if (category == "engagement") {
      engagement_count += 1;
      engagement_sum += score;
    } else if (category == "program-check") {
      program_check_sum += score;
    } else {
      cout << "ignored invalid input" << endl;
    }

    // get the next line from standard input
    getline(cin, line);
  }

  double exam_average = max(exam_sum / exam_count, final_exam);
  double hw_average = hw_sum / hw_count;
  double lw_average = lw_sum / lw_count;
  double reading = min(reading_sum / reading_count + 15, 100.);
  double engagement = min(engagement_sum / engagement_count + 15, 100.);

  // it might be nan
  exam_average = (exam_average != exam_average) ? 0 : exam_average;
  hw_average = (hw_average != hw_average) ? 0 : hw_average;
  lw_average = (lw_average != lw_average) ? 0 : lw_average * 100;
  // these two are always greater than 15
  reading = (reading != reading) ? 15 : reading;
  engagement = (engagement != engagement) ? 15 : engagement;

  // check the condition of the program check
  if (program_check_sum == 1) {
    lw_average *= 0.75;
  } else if (program_check_sum == 0) {
    lw_average *= 0.5;
  }

  const double exam_weight = 0.4;
  const double hw_weight = 0.4;
  const double lw_weight = 0.1;
  const double reading_weight = 0.05;
  const double engagement_weight = 0.05;
  double weighted_total = exam_average * exam_weight + hw_average * hw_weight +
                          lw_average * lw_weight + reading * reading_weight +
                          engagement * engagement_weight;

  char final_letter_grade = 'F';

  if (weighted_total >= 90) {
    final_letter_grade = 'A';
  } else if (weighted_total >= 80) {
    final_letter_grade = 'B';
  } else if (weighted_total >= 70) {
    final_letter_grade = 'C';
  } else if (weighted_total >= 60) {
    final_letter_grade = 'D';
  }

  print_results(exam_average, hw_average, lw_average, reading, engagement,
                weighted_total, final_letter_grade);
}

// These methods are already implemented for you
// You should not need to modify them

void print_instructions() {
  cout << "enter grades as <category> <score>" << endl;
  cout << "  <category> := exam | final-exam | hw | lw | reading | engagement "
          "| program-check"
       << endl;
  cout << "     <score> := numeric value" << endl;
  cout << "enter an empty line to end input" << endl;
}

void get_category_and_score(const string &line, string *category,
                            double *score) {
  // turn the string into an input stream
  std::istringstream sin(line);

  // read the category (as string) and score (as double) from the stream
  sin >> *category;
  sin >> *score;

  if (sin.fail()) {
    // the stream is in a fail state (something went wrong)
    // clear the flags
    sin.clear();
    // clear the stream buffer (throw away whatever garbage is in there)
    sin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    // signal that the line was invalid
    *category = "ignore";
  }
}

void print_results(double exam_average, double hw_average, double lw_average,
                   double reading, double engagement, double weighted_total,
                   char final_letter_grade) {
  cout << "summary:" << endl;
  cout << "      exam average: " << exam_average << endl;
  cout << "        hw average: " << hw_average << endl;
  cout << "        lw average: " << lw_average << endl;
  cout << "           reading: " << reading << endl;
  cout << "        engagement: " << engagement << endl;
  cout << "    ---------------" << endl;

  cout << "    weighted total: " << weighted_total << endl;

  cout << "final letter grade: " << final_letter_grade << endl;
}

double min(double a, double b) {
  if (a > b) {
    return b;
  }
  return a;
}

double max(double a, double b) {
  if (a < b) {
    return b;
  }
  return a;
}
