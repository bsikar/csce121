#include "functions.h"
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>

using std::cout, std::endl, std::string;

void initializeImage(Pixel image[][MAX_HEIGHT]) {
  // iterate through columns
  for (unsigned int col = 0; col < MAX_WIDTH; col++) {
    // iterate through rows
    for (unsigned int row = 0; row < MAX_HEIGHT; row++) {
      // initialize pixel
      image[col][row] = {0, 0, 0};
    }
  }
}

void loadImage(string filename, Pixel image[][MAX_HEIGHT], unsigned int &width,
               unsigned int &height) {
  // initalize a new image
  initializeImage(image);

  // open the file, but if it cannot be opened at run time throw a runtime_error
  // `Failed to open <filename>"
  std::ifstream input_file(filename);

  if (!input_file.is_open()) {
    throw std::runtime_error("Failed to open " + filename);
  }

  // if the file is not a p3 or P3 throw a runtime exception: "Invalid type
  // <type>"
  string line;
  input_file >> line;
  if (line != "p3" && line != "P3") {
    throw std::runtime_error("Invalid type " + line);
  }

  // read the width and height
  input_file >> width >> height;

  // if the width or height are greater than the MAX_WIDTH and MAX_HEIGHT then
  // throw a runtime error "Invalid dimensions"
  if (width > MAX_WIDTH || height > MAX_HEIGHT) {
    throw std::runtime_error("Invalid dimensions");
  }

  // skip the third line
  input_file >> line;

  int count = 0;
  int rgb_single;

  // iterate through every rgb value
  unsigned int row_index = 0;
  unsigned int col_index = 0;
  while (input_file >> rgb_single) {
  }

  // close the file
  input_file.close();
}

void outputImage(string filename, Pixel image[][MAX_HEIGHT], unsigned int width,
                 unsigned int height) {}

unsigned int energy(Pixel image[][MAX_HEIGHT], unsigned int x, unsigned int y,
                    unsigned int width, unsigned int height) {
  // TODO: implement (part 1)
  return 0;
}

// uncomment functions as you implement them (part 2)

// unsigned int loadVerticalSeam(Pixel image[][MAX_HEIGHT], unsigned int
// start_col, unsigned int width, unsigned int height, unsigned int seam[]) {
//   // TODO: implement (part 2)
//   return 0;
// }

// unsigned int loadHorizontalSeam(Pixel image[][MAX_HEIGHT], unsigned int
// start_row, unsigned int width, unsigned int height, unsigned int seam[]) {
//   // TODO: implement (part 2)
//   return 0;
// }

// void findMinVerticalSeam(Pixel image[][MAX_HEIGHT], unsigned int width,
// unsigned int height, unsigned int seam[]) {
//   // TODO: implement (part 2)
// }

// void findMinHorizontalSeam(Pixel image[][MAX_HEIGHT], unsigned int width,
// unsigned int height, unsigned int seam[]) {
//   // TODO: implement (part 2)
// }

// void removeVerticalSeam(Pixel image[][MAX_HEIGHT], unsigned int& width,
// unsigned int height, unsigned int verticalSeam[]) {
//   // TODO: implement (part 2)
// }

// void removeHorizontalSeam(Pixel image[][MAX_HEIGHT], unsigned int width,
// unsigned int& height, unsigned int horizontalSeam[]) {
//   // TODO: implement (part 2)
// }
