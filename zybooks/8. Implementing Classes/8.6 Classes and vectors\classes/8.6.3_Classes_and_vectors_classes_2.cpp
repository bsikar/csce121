#include <iostream>
#include <vector>
using namespace std;

class Lesson {
public:
  bool ReadDetails();
  void Print() const;

private:
  string topic;
  int duration;
};

bool Lesson::ReadDetails() {
  string newTopic;

  cin >> newTopic;
  if (newTopic == "completed") {
    return false;
  } else {
    topic = newTopic;
    cin >> duration;
    return true;
  }
}

void Lesson::Print() const {
  cout << "Lesson: " << topic << ", Duration: " << duration << endl;
}

int main() {
  unsigned int i;
  vector<Lesson> lessonList;
  Lesson currLesson;
  bool result;

  result = currLesson.ReadDetails();
  while (result) {
    lessonList.push_back(currLesson);
    result = currLesson.ReadDetails();
  }

  for (i = 0; i < lessonList.size(); ++i) {
    currLesson = lessonList.at(i);
    currLesson.Print();
  }

  return 0;
}
