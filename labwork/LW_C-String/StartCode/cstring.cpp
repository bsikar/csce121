#include "cstring.h"
#include <iostream>

unsigned int length(char str[]) {
  unsigned int i = 0;
  for (char *c = str; *c; c++) {
    i++;
  }
  return i;
}

unsigned int find(char str[], char character) {
  // returns
  //  - the index of the first occurence of character in str
  //  - the size if the character is not found
  unsigned int i = 0;
  for (char *c = str; *c; c++) {
    if (*c == character) {
      return i;
    }
    i++;
  }
  return i;
}

bool equalStr(char str1[], char str2[]) {
  unsigned int len1 = length(str1);
  unsigned int len2 = length(str2);

  if (len1 != len2) {
    return false;
  }

  for (unsigned int i = 0; i < len1; i++) {
    if (str1[i] != str2[i]) {
      return false;
    }
  }
  return true;
}
