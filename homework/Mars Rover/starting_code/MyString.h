#ifndef _MYSTRING_H
#define _MYSTRING_H

#include <iostream>

using std::ostream;

class MyString {
public:
  MyString(const MyString &other);     // copy constructor
  MyString(const char *str = nullptr); // c-string and default
  MyString(const std::string &str);    // from std::string
  ~MyString();
  void resize(unsigned int n);
  unsigned int capacity() const noexcept;
  unsigned int size() const noexcept;
  unsigned int length() const noexcept;
  char *data() const noexcept;
  bool empty() const noexcept;
  const char &front() const;
  const char &at(unsigned int pos) const;
  void clear() noexcept;
  MyString &operator=(const char *str);
  MyString &operator=(const std::string &str);
  MyString &operator=(const MyString &other);
  MyString &operator+=(const char *str);
  MyString &operator+=(const std::string &str);
  MyString &operator+=(const MyString &other);
  MyString operator+(const MyString &other);
  bool operator==(const MyString &other);
  unsigned long find(const std::string &str,
                     unsigned int pos = 0) const noexcept;
  unsigned long find(const char *str, unsigned int pos = 0) const noexcept;
  unsigned long find(const MyString &str, unsigned int pos = 0) const noexcept;
  friend std::ostream &operator<<(std::ostream &os, const MyString &str);

private:
  const unsigned int step = 1;
  char *data_;
  unsigned int capacity_;
  unsigned int size_;
};

#endif
