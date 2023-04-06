#include <iostream>
#include <string>
using namespace std;

class Voicemail {
public:
  void SetName(string voicemailName);
  void SetGreeting(string voicemailGreeting);
  void SetNumber(int voicemailNumber);
  void Print();

private:
  /* Your code goes here */
  string name = "Unspecified";
  string greeting = "Incomplete";
  int number = 1;
};

void Voicemail::SetName(string voicemailName) { name = voicemailName; }

void Voicemail::SetGreeting(string voicemailGreeting) {
  greeting = voicemailGreeting;
}

void Voicemail::SetNumber(int voicemailNumber) { number = voicemailNumber; }

void Voicemail::Print() {
  cout << "Name: " << name << ", Greeting: " << greeting
       << " is not available now, Number: " << number << endl;
}

int main() {
  string newName;
  int newNumber;
  Voicemail favoriteVoicemail;

  favoriteVoicemail.Print();

  cin >> newName;
  cin >> newNumber;

  favoriteVoicemail.SetName(newName);
  favoriteVoicemail.SetGreeting(newName);
  favoriteVoicemail.SetNumber(newNumber);

  favoriteVoicemail.Print();

  return 0;
}
