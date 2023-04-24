#include <iostream>
using namespace std;

class FrogNode {
public:
  FrogNode(int tadpolesInit = 0, FrogNode *nextLoc = nullptr);
  void InsertAfter(FrogNode *nodeLoc);
  FrogNode *GetNext();
  int GetNodeData();

private:
  int tadpolesVal;
  FrogNode *nextNodePtr;
};

FrogNode::FrogNode(int tadpolesInit, FrogNode *nextLoc) {
  this->tadpolesVal = tadpolesInit;
  this->nextNodePtr = nextLoc;
}

void FrogNode::InsertAfter(FrogNode *nodeLoc) {
  FrogNode *tmpNext = nullptr;

  tmpNext = this->nextNodePtr;
  this->nextNodePtr = nodeLoc;
  nodeLoc->nextNodePtr = tmpNext;
}

FrogNode *FrogNode::GetNext() { return this->nextNodePtr; }

int FrogNode::GetNodeData() { return this->tadpolesVal; }

int main() {
  FrogNode *headFrog = nullptr;
  FrogNode *currFrog = nullptr;
  FrogNode *lastFrog = nullptr;
  int count;
  int inputValue;
  int i;
  int sum;

  cin >> count;

  headFrog = new FrogNode(count);
  lastFrog = headFrog;

  for (i = 0; i < count; ++i) {
    cin >> inputValue;

    currFrog = new FrogNode(inputValue);

    lastFrog->InsertAfter(currFrog);
    lastFrog = currFrog;
  }

  /* Your code goes here */
  currFrog = headFrog;
  sum = 0;
  while (currFrog != nullptr) {
    sum += currFrog->GetNodeData();
    currFrog = currFrog->GetNext();
  }
  cout << sum << endl;

  return 0;
}
