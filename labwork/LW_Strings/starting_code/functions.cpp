#include "functions.h"
// add any includes

using std::cout, std::cin, std::endl, std::string;

void deobfuscate() {
  string obfuscated_sentence;
  string obfuscated_details;
  string output;

  cout << "Please enter obfuscated sentence: ";
  cin >> obfuscated_sentence;

  cout << "Please enter deobfuscation details: ";
  cin >> obfuscated_details;

  int prev_length = 0;
  for (char c : obfuscated_details) {
    int length = c - '0';

    output.append(obfuscated_sentence.substr(prev_length, length));
    output.push_back(' ');
    prev_length += length;
  }
  // remove the last letter from output
  output = output.substr(0, output.length() - 1);

  cout << "Deobfuscated sentence: " << output << endl;
}

void wordFilter() {
  string sentence;
  string filter_word;
  string output;

  cout << "Please enter the sentence: ";
  getline(cin, sentence);

  cout << "Please enter the filter word: ";
  cin >> filter_word;

  int word_location = sentence.find(filter_word);

  while (word_location != -1) {
    // replace the word with '#'s
    sentence.replace(word_location, filter_word.length(), string(filter_word.length(), '#'));

    word_location = sentence.find(filter_word);
  }

  cout << "Filtered sentence: " << sentence << endl;
}

void passwordConverter() {
  string input;

  cout << "Please enter your text input: input: ";
  getline(cin, input);

  const int size = 5;
  char values_to_replace[size] = {'a', 'e', 'i', 'o', 'u'};
  char values_replace_with[size] = {'@', '3', '!', '0', '^'};

  for (int i = 0; i < static_cast<int>(input.length()); i++) {
    for (int j = 0; j < size; j++) {
      if (input[i] == values_to_replace[j]) {
        input[i] = values_replace_with[j];
      }
    }
  }

  string reversed_string = input;
  for (int i = 0; i < static_cast<int>(input.length()); i++) {
    reversed_string[i] = input[input.length() - i - 1];
  }
  cout << "\noutput: " << input + reversed_string << endl;
}

void wordCalculator() {
  // TODO
}

void palindromeCounter() {
  // TODO
}
