#include <iostream>
#include <string>
using namespace std;

class Book {
public:
  Book();
  void SetNumWords(int bookNumWords);
  void SetYear(int bookYear);
  void SetTitle(string bookTitle);
  void Print();

private:
  int numWords;
  int year;
  string title;
};

Book::Book() {
  numWords = 0;
  year = -1;
  title = "Undefined";
}

void Book::SetNumWords(int bookNumWords) { numWords = bookNumWords; }

void Book::SetYear(int bookYear) { year = bookYear; }

void Book::SetTitle(string bookTitle) { title = bookTitle; }

void Book::Print() {
  cout << "Number of words: " << numWords << ", Year: " << year
       << ", Title: " << title << endl;
}

int main() {
  int newNumWords;
  int newYear;
  string newTitle;
  Book myBook;

  myBook.Print();

  cin >> newNumWords;
  cin >> newYear;
  cin >> newTitle;

  myBook.SetNumWords(newNumWords);
  myBook.SetYear(newYear);
  myBook.SetTitle(newTitle);

  myBook.Print();

  return 0;
}
