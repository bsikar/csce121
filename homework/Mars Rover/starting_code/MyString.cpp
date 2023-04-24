#include "MyString.h"
#include <stdexcept>

void memcpy(char *dest, const char *src, unsigned int len) {
  for (unsigned int i = 0; i < len; i++) {
    dest[i] = src[i];
  }
}

unsigned int strlen(const char *str) {
  const char *s = str;
  while (*s != '\0') {
    s += 1;
  }
  return s - str;
}

int memcmp(const char *str1, const char *str2, unsigned int len) {
  for (unsigned int i = 0; i < len; i++) {
    if (str1[i] != str2[i]) {
      return str1[i] < str2[i] ? -1 : 1;
    }
  }
  return 0;
}

MyString::MyString(const MyString &other)
    : data_(new char[other.capacity_]), capacity_(other.capacity_),
      size_(other.size_) {
  memcpy(data_, other.data_, size_);
}

MyString::MyString(const char *str)
    : data_(nullptr), capacity_(step), size_(0) {
  if (str != nullptr) {
    size_ = strlen(str);
    capacity_ = size_ + step;
  }
  data_ = new char[capacity_];
  memcpy(data_, str, size_);
  data_[size_] = '\0';
}

MyString::MyString(const std::string &str)
    : data_(nullptr), capacity_(0), size_(0) {
  size_ = str.size();
  capacity_ = size_ + step;
  data_ = new char[capacity_];
  memcpy(data_, str.c_str(), size_);
  data_[size_] = '\0';
}

MyString::~MyString() {
  size_ = 0;
  capacity_ = 0;
  delete[] data_;
}

void MyString::resize(unsigned int n) {
  if (n < capacity_) {
    size_ = n;
    data_[size_] = '\0';
    return;
  }

  char *data_ = new char[n];
  memcpy(data_, this->data_, n);
  delete[] this->data_;
  this->data_ = data_;
}

unsigned int MyString::capacity() const noexcept { return capacity_; }
unsigned int MyString::size() const noexcept { return size_; }
unsigned int MyString::length() const noexcept { return size_; }
char *MyString::data() const noexcept { return data_; }
bool MyString::empty() const noexcept { return size_ == 0; }
const char &MyString::front() const { return *data_; }
const char &MyString::at(unsigned int pos) const {
  if (pos >= size_) {
    throw std::out_of_range("value was out of range");
  }
  return data_[pos];
}

void MyString::clear() noexcept {
  size_ = 0;
  data_[size_] = '\0';
}

MyString &MyString::operator=(const char *str) {
  if (str == nullptr) {
    return *this;
  }

  size_ = strlen(str);
  if (size_ > capacity_) {
    capacity_ = size_ + step;
    delete[] data_;
    data_ = new char[capacity_];
  }
  memcpy(data_, str, size_);
  data_[size_] = '\0';
  return *this;
}

MyString &MyString::operator=(const std::string &str) {
  size_ = str.size();
  if (size_ > capacity_) {
    capacity_ = size_ + step;
    delete[] data_;
    data_ = new char[capacity_];
  }
  memcpy(data_, str.c_str(), size_);
  data_[size_] = '\0';
  return *this;
}

MyString &MyString::operator=(const MyString &other) {
  if (this == &other) {
    return *this;
  }
  size_ = other.size_;
  if (size_ > capacity_) {
    capacity_ = size_ + step;
    delete[] data_;
    data_ = new char[capacity_];
  }
  memcpy(data_, other.data_, size_);
  data_[size_] = '\0';
  return *this;
}

MyString &MyString::operator+=(const char *str) {
  if (str == nullptr) {
    return *this;
  }

  unsigned int len = strlen(str);
  if (size_ + len > capacity_) {
    capacity_ = size_ + len + step;
    char *data_ = new char[capacity_];
    memcpy(data_, this->data_, size_);
    delete[] this->data_;
    this->data_ = data_;
  }
  memcpy(data_ + size_, str, len);
  size_ += len;
  data_[size_] = '\0';
  return *this;
}

MyString &MyString::operator+=(const std::string &str) {
  unsigned int len = str.size();
  if (size_ + len > capacity_) {
    capacity_ = size_ + len + step;
    char *data_ = new char[capacity_];
    memcpy(data_, this->data_, size_);
    delete[] this->data_;
    this->data_ = data_;
  }
  memcpy(data_ + size_, str.c_str(), len);
  size_ += len;
  data_[size_] = '\0';
  return *this;
}

MyString &MyString::operator+=(const MyString &other) {
  unsigned int len = other.size_;
  if (size_ + len > capacity_) {
    capacity_ = size_ + len + step;
    char *data_ = new char[capacity_];
    memcpy(data_, this->data_, size_);
    delete[] this->data_;
    this->data_ = data_;
  }
  memcpy(data_ + size_, other.data_, len);
  size_ += len;
  data_[size_] = '\0';
  return *this;
}

MyString MyString::operator+(const MyString &other) {
  unsigned int len = other.size_;
  char *data_ = new char[capacity_];
  if (size_ + len > capacity_) {
    capacity_ = size_ + len;
    memcpy(data_, this->data_, size_);
  }
  memcpy(data_ + size_, other.data_, len);
  data_[size_] = '\0';
  MyString mystring = MyString(data_);
  return mystring;
}

bool MyString::operator==(const MyString &other) {
  if (size_ != other.size_) {
    return false;
  }

  return !memcmp(data_, other.data_, size_);
}

unsigned long MyString::find(const char *str, unsigned int pos) const noexcept {
  if (str == nullptr) {
    return std::string::npos;
  }

  unsigned int len = strlen(str);
  if (len == 0) {
    return std::string::npos;
  }

  for (unsigned int i = pos; i <= size_ - len; i++) {
    if (memcmp(data_ + i, str, len) == 0) {
      return i;
    }
  }
  return std::string::npos;
}

unsigned long MyString::find(const std::string &str,
                             unsigned int pos) const noexcept {
  unsigned long len = str.size();
  if (len == 0) {
    return std::string::npos;
  }
  for (unsigned int i = pos; i <= size_ - len; i++) {
    if (memcmp(data_ + i, str.c_str(), len) == 0) {
      return i;
    }
  }
  return std::string::npos;
}

unsigned long MyString::find(const MyString &str,
                             unsigned int pos) const noexcept {
  unsigned long len = str.size_;
  if (len == 0) {
    return std::string::npos;
  }
  for (unsigned int i = pos; i <= size_ - len; i++) {
    if (memcmp(data_ + i, str.data_, len) == 0) {
      return i;
    }
  }
  return std::string::npos;
}

std::ostream &operator<<(std::ostream &os, const MyString &str) {
  os << str.data_;
  return os;
}
