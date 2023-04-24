#include <iostream>
using namespace std;

class ChickenNode {
public:
  ChickenNode(int chicksInit = 0, ChickenNode *nextLoc = nullptr);
  void InsertAfter(ChickenNode *nodeLoc);
  ChickenNode *GetNext();
  void PrintNodeData();

private:
  int chicksVal;
  ChickenNode *nextNodePtr;
};

ChickenNode::ChickenNode(int chicksInit, ChickenNode *nextLoc) {
  this->chicksVal = chicksInit;
  this->nextNodePtr = nextLoc;
}

void ChickenNode::InsertAfter(ChickenNode *nodeLoc) {
  ChickenNode *tmpNext = nullptr;

  tmpNext = this->nextNodePtr;
  this->nextNodePtr = nodeLoc;
  nodeLoc->nextNodePtr = tmpNext;
}

ChickenNode *ChickenNode::GetNext() { return this->nextNodePtr; }

void ChickenNode::PrintNodeData() { cout << this->chicksVal << endl; }

int main() {
  ChickenNode *headObj = nullptr;
  ChickenNode *firstChicken = nullptr;
  ChickenNode *secondChicken = nullptr;
  ChickenNode *currChicken = nullptr;
  int chicks1;
  int chicks2;

  cin >> chicks1;
  cin >> chicks2;

  headObj = new ChickenNode(-1);

  firstChicken = new ChickenNode(chicks1);
  secondChicken = new ChickenNode(chicks2);
  headObj->InsertAfter(firstChicken);
  firstChicken->InsertAfter(secondChicken);

  currChicken = headObj->GetNext();
  while (currChicken != nullptr) {
    currChicken->PrintNodeData();
    currChicken = currChicken->GetNext();
  }

  return 0;
}
