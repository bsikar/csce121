#include <iostream>
using namespace std;

class TownNode {
public:
  TownNode(int neighborsInit = 0, TownNode *nextLoc = nullptr);
  void InsertAfter(TownNode *nodeLoc);
  TownNode *GetNext();
  void PrintNodeData();

private:
  int neighborsVal;
  TownNode *nextNodePtr;
};

TownNode::TownNode(int neighborsInit, TownNode *nextLoc) {
  this->neighborsVal = neighborsInit;
  this->nextNodePtr = nextLoc;
}

void TownNode::InsertAfter(TownNode *nodeLoc) {
  TownNode *tmpNext = nullptr;

  tmpNext = this->nextNodePtr;
  this->nextNodePtr = nodeLoc;
  nodeLoc->nextNodePtr = tmpNext;
}

TownNode *TownNode::GetNext() { return this->nextNodePtr; }

void TownNode::PrintNodeData() { cout << this->neighborsVal << endl; }

int main() {
  TownNode *headTown = nullptr;
  TownNode *currTown = nullptr;
  TownNode *lastTown = nullptr;
  int townCount;
  int inputValue;
  int i;

  cin >> townCount;

  headTown = new TownNode(townCount);
  lastTown = headTown;

  for (i = 0; i < townCount; i++) {
    cin >> inputValue;
    currTown = new TownNode(inputValue);
    lastTown->InsertAfter(currTown);
    lastTown = currTown;
  }

  currTown = headTown;

  while (currTown != nullptr) {
    currTown->PrintNodeData();
    currTown = currTown->GetNext();
  }

  return 0;
}
