#include "helper.h"

struct Person {
  string name;       // "name" member variable
  unsigned char age; // "age" member variable
};

void foo(int value, int &reference, int *pointer) {
  value = 1;     // will not change num
  reference = 1; // will change num

  *pointer = 1; // will change the value at the memory address of num
  pointer =
      nullptr; // does not persist as the actual pointer variable is a copy
}

int main() {
  outputHeading("Structs");

  {
    Person jackson = {"Jackson Hagood", 21}; // can initialize with list

    // use '.' to get a member
    cout << "Person name: " << jackson.name << '\n';
    cout << "Person age: " << (int)jackson.age << '\n';
  }

  promptInput();
  outputHeading("Pointers");

  {
    int num = 1;
    int *pointer = &num;

    cout << "Num value: " << num << '\n';    // value of num
    cout << "Num address: " << &num << '\n'; // address of num

    cout << "\nPointer value: " << pointer << '\n'; // value of pointer
    cout << "Pointer dereferenced: " << *pointer
         << '\n'; // value at the location stored in pointer
    cout << "Pointer address: " << &pointer << '\n'; // address of pointer

    cout << "\n+-----------------Stack Diagram------------------+\n|    "
            "address     |     value      |  identifier  "
            "|\n+----------------+----------------+--------------+\n|       "
            "...      |      ...       |     ...      |\n| "
         << &num << " |       " << num
         << "        |     num      |<-+\n|       ...      |      ...       |  "
            "   ...      |  | pointer \"points to\" num\n| "
         << &pointer << " | " << pointer
         << " |   pointer    |--+\n|       ...      |      ...       |     ... "
            "     |\n+----------------+----------------+--------------+\n";
  }

  promptInput();
  outputHeading("Passing Variables into Functions");

  {
    int num1 = 0;
    int num2 = 0;
    int num3 = 0;

    cout << "Values before function call: \n";
    cout << "Num 1: " << num1 << '\n';
    cout << "Num 2: " << num2 << '\n';
    cout << "Num 3: " << num3 << '\n';

    foo(num1, num2, &num3);

    cout << "\nValues after function call: \n";
    cout << "Num 1: " << num1 << " (pass by value)\n";
    cout << "Num 2: " << num2 << " (pass by reference)\n";
    cout << "Num 3: " << num3 << " (pass by pointer)\n";
  }

  promptInput();
  outputHeading("Dynamic Memory");

  {
    int *heapPointer = new int{3}; // pointer to an integer created on the heap
                                   // (managed by the programmer)

    cout << "Pointer value: " << heapPointer
         << '\n'; // "heapPointer" is a pointer to an integer, not the integer
                  // itself
    cout << "Pointer dereferenced: " << *heapPointer << '\n';
    cout << "Pointer address: " << &heapPointer
         << '\n'; // because pointers are themselves variables, they have their
                  // own memory location (on the stack)

    cout << "\n+-----------------Stack Diagram------------------+     "
            "+------Heap Diagram------+\n|    address     |     value      |  "
            "identifier  |     |    address     | value "
            "|\n+----------------+----------------+--------------+     "
            "+----------------+-------+\n|       ...      |      ...       |   "
            "  ...      |     |       ...      |  ...  |\n| "
         << &heapPointer << " | " << heapPointer << " | heapPointer  |---->| "
         << heapPointer << " |   " << *heapPointer
         << "   |\n|       ...      |      ...       |     ...      |     |    "
            "   ...      |  ...  "
            "|\n+----------------+----------------+--------------+     "
            "+----------------+-------+\n";

    delete heapPointer; // must deallocate memory on the heap before access is
                        // lost to it (pointer on stack goes out of scope)

    cout << "\nMemory deallocated\n";
    cout << "Pointer value: " << heapPointer
         << '\n'; // the pointer variable's value is not changed (dangling
                  // pointer)

    heapPointer =
        nullptr; // it is best to set to nullptr after the memory is deleted

    cout << "\nDangling pointer handled\n";
    cout << "Pointer value (nullptr): " << heapPointer << '\n';
  }

  promptInput();
  outputHeading("Dynamic Arrays");

  {
    unsigned int size = 3;
    char *array = new char[size]{'O', 'O', 'O'};

    cout << "+-----------------Stack Diagram------------------+     "
            "+------Heap Diagram------+\n|    address     |     value      |  "
            "identifier  |     |    address     | value "
            "|\n+----------------+----------------+--------------+     "
            "+----------------+-------+\n|       ...      |      ...       |   "
            "  ...      |     |      ...       |  ...  |\n| "
         << (void *)&array << " | " << (void *)array
         << " |    array     |---->| " << (void *)&(array[0]) << " |  '"
         << array[0]
         << "'  |\n|       ...      |      ...       |     ...      |     | "
         << (void *)&(array[1]) << " |  '" << array[1]
         << "'  |\n+----------------+----------------+--------------+     | "
         << (void *)&(array[2]) << " |  '" << array[2]
         << "'  |\n                                                       |    "
            "  ...       |  ...  |\n                                           "
            "            +----------------+-------+\n";
    promptInput();

    {
      char *newArray = new char[size * 2]{
          'N', 'N', 'N', 'N', 'N', 'N'}; // allocate memory for new array

      outputHeading("Step 1: New Array Allocated");
      cout << "+-----------------Stack Diagram------------------+     "
              "+------Heap Diagram------+\n|    address     |     value      | "
              " identifier  |     |    address     | value "
              "|\n+----------------+----------------+--------------+     "
              "+----------------+-------+\n|       ...      |      ...       | "
              "    ...      |     |      ...       |  ...  |\n| "
           << (void *)&array << " | " << (void *)array
           << " |    array     |---->| " << (void *)&(array[0]) << " |  '"
           << array[0]
           << "'  |\n|       ...      |      ...       |     ...      |     | "
           << (void *)&(array[1]) << " |  '" << array[1] << "'  |\n| "
           << (void *)&newArray << " | " << (void *)newArray
           << " |   newArray   |--+  | " << (void *)&(array[2]) << " |  '"
           << array[2]
           << "'  |\n|       ...      |      ...       |     ...      |  |  |  "
              "    ...       |  ...  "
              "|\n+----------------+----------------+--------------+  +->| "
           << (void *)&(newArray[0]) << " |  '" << newArray[0]
           << "'  |\n                                                       | "
           << (void *)&(newArray[1]) << " |  '" << newArray[1]
           << "'  |\n                                                       | "
           << (void *)&(newArray[2]) << " |  '" << newArray[2]
           << "'  |\n                                                       | "
           << (void *)&(newArray[3]) << " |  '" << newArray[3]
           << "'  |\n                                                       | "
           << (void *)&(newArray[4]) << " |  '" << newArray[4]
           << "'  |\n                                                       | "
           << (void *)&(newArray[5]) << " |  '" << newArray[5]
           << "'  |\n                                                       |  "
              "    ...       |  ...  |\n                                       "
              "                +----------------+-------+\n";
      promptInput();

      for (unsigned int i = 0; i < size; i++) {
        newArray[i] = array[i]; // copy elements from old to new array
      }

      outputHeading("Step 2: Values Copied Over");
      cout << "+-----------------Stack Diagram------------------+     "
              "+------Heap Diagram------+\n|    address     |     value      | "
              " identifier  |     |    address     | value "
              "|\n+----------------+----------------+--------------+     "
              "+----------------+-------+\n|       ...      |      ...       | "
              "    ...      |     |      ...       |  ...  |\n| "
           << (void *)&array << " | " << (void *)array
           << " |    array     |---->| " << (void *)&(array[0]) << " |  '"
           << array[0]
           << "'  |\n|       ...      |      ...       |     ...      |     | "
           << (void *)&(array[1]) << " |  '" << array[1] << "'  |\n| "
           << (void *)&newArray << " | " << (void *)newArray
           << " |   newArray   |--+  | " << (void *)&(array[2]) << " |  '"
           << array[2]
           << "'  |\n|       ...      |      ...       |     ...      |  |  |  "
              "    ...       |  ...  "
              "|\n+----------------+----------------+--------------+  +->| "
           << (void *)&(newArray[0]) << " |  '" << newArray[0]
           << "'  |\n                                                       | "
           << (void *)&(newArray[1]) << " |  '" << newArray[1]
           << "'  |\n                                                       | "
           << (void *)&(newArray[2]) << " |  '" << newArray[2]
           << "'  |\n                                                       | "
           << (void *)&(newArray[3]) << " |  '" << newArray[3]
           << "'  |\n                                                       | "
           << (void *)&(newArray[4]) << " |  '" << newArray[4]
           << "'  |\n                                                       | "
           << (void *)&(newArray[5]) << " |  '" << newArray[5]
           << "'  |\n                                                       |  "
              "    ...       |  ...  |\n                                       "
              "                +----------------+-------+\n";
      promptInput();

      delete[] array; // deallocate memory of old array

      outputHeading("Step 3: Old Array Deallocated");
      cout << "+-----------------Stack Diagram------------------+     "
              "+------Heap Diagram------+\n|    address     |     value      | "
              " identifier  |     |    address     | value "
              "|\n+----------------+----------------+--------------+     "
              "+----------------+-------+\n|       ...      |      ...       | "
              "    ...      |     |      ...       |  ...  |\n| "
           << (void *)&array << " | " << (void *)array
           << " |    array     |  +->| " << (void *)&(newArray[0]) << " |  '"
           << newArray[0]
           << "'  |\n|       ...      |      ...       |     ...      |  |  | "
           << (void *)&(newArray[1]) << " |  '" << newArray[1] << "'  |\n| "
           << (void *)&newArray << " | " << (void *)newArray
           << " |   newArray   |--+  | " << (void *)&(newArray[2]) << " |  '"
           << newArray[2]
           << "'  |\n|       ...      |      ...       |     ...      |     | "
           << (void *)&(newArray[3]) << " |  '" << newArray[3]
           << "'  |\n+----------------+----------------+--------------+     | "
           << (void *)&(newArray[4]) << " |  '" << newArray[4]
           << "'  |\n                                                       | "
           << (void *)&(newArray[5]) << " |  '" << newArray[5]
           << "'  |\n                                                       |  "
              "    ...       |  ...  |\n                                       "
              "                +----------------+-------+\n";
      promptInput();

      array = newArray; // update array pointer
      size *= 2;        // update any size variables

      outputHeading("Step 4: Array Pointer Updated");
      cout << "+-----------------Stack Diagram------------------+     "
              "+------Heap Diagram------+\n|    address     |     value      | "
              " identifier  |     |    address     | value "
              "|\n+----------------+----------------+--------------+     "
              "+----------------+-------+\n|       ...      |      ...       | "
              "    ...      |     |      ...       |  ...  |\n| "
           << (void *)&array << " | " << (void *)array
           << " |    array     |--+->| " << (void *)&(array[0]) << " |  '"
           << array[0]
           << "'  |\n|       ...      |      ...       |     ...      |  |  | "
           << (void *)&(array[1]) << " |  '" << array[1] << "'  |\n| "
           << (void *)&newArray << " | " << (void *)newArray
           << " |   newArray   |--+  | " << (void *)&(array[2]) << " |  '"
           << array[2]
           << "'  |\n|       ...      |      ...       |     ...      |     | "
           << (void *)&(array[3]) << " |  '" << array[3]
           << "'  |\n+----------------+----------------+--------------+     | "
           << (void *)&(array[4]) << " |  '" << array[4]
           << "'  |\n                                                       | "
           << (void *)&(array[5]) << " |  '" << array[5]
           << "'  |\n                                                       |  "
              "    ...       |  ...  |\n                                       "
              "                +----------------+-------+\n";
    }

    delete[] array;
  }

  promptInput();
  outputHeading("Multi-dimensional Arrays");

  {
    unsigned int w = 2; // width (x, dimension 1)
    unsigned int h = 3; // height (y, dimension 2)
    unsigned int d = 4; // depth (z, dimension 3)

    // 3 pointers for 3 dimensions
    int ***array = new int **[w]; // allocate dimension 1

    for (unsigned int x = 0; x < w; x++) { // iterate through dimension 1
      array[x] = new int *[h];             // allocate dimension 2

      for (unsigned int y = 0; y < h; y++) { // iterate through dimension 2
        array[x][y] = new int[d];            // allocate dimension 3

        for (unsigned int z = 0; z < d; z++) { // iterate through dimension 3
          array[x][y][z] = 0;                  // initialize dimension 3
        }
      }
    }

    cout << "3D array allocated (" << w << " x " << h << " x " << d << ")\n";

    for (unsigned int x = 0; x < w; x++) {
      for (unsigned int y = 0; y < h; y++) {
        delete[] array[x][y]; // delete third dimension
      }

      delete[] array[x]; // delete second dimension
    }

    delete[] array; // delete first dimension

    cout << "3D array deallocated (" << w << " x " << h << " x " << d << ")\n";

    array = nullptr;
    w = 0;
    h = 0;
    d = 0;
  }

  promptInput();

  return 0;
}
