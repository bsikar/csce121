#include "functions.h"
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>

using std::cout;
using std::endl;
using std::string;

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

void printImage(const Pixel image[][MAX_HEIGHT], unsigned int width,
                unsigned int height) {
  for (unsigned int row_index = 0; row_index < height; row_index++) {
    for (unsigned int col_index = 0; col_index < width; col_index++) {
      cout << "{" << image[col_index][row_index].r << ", "
           << image[col_index][row_index].g << ", "
           << image[col_index][row_index].b << "}";
      if (col_index < width - 1) {
        cout << ", ";
      }
    }
    cout << endl;
  }
}

void loadImage(string filename, Pixel image[][MAX_HEIGHT], unsigned int &width,
               unsigned int &height) {
  std::ifstream input_file(filename);

  if (!input_file) {
    throw std::runtime_error("Failed to open " + filename);
  }

  // Read in the PPM header information
  string line;
  int maxColorValue;
  input_file >> line >> width >> height >> maxColorValue;

  // Validate the header information
  if (line != "P3" && line != "p3") {
    throw std::runtime_error("Invalid type " + line);
  }
  if (width <= 0 || height <= 0 || width > MAX_WIDTH || height > MAX_HEIGHT) {
    throw std::runtime_error("Invalid dimensions");
  }
  if (maxColorValue != 255) {
    throw std::runtime_error("Invalid color value");
  }

  // Read in the pixel values
  int red, green, blue;
  for (unsigned int j = 0; j < height; j++) {
    for (unsigned int i = 0; i < width; i++) {
      if (!(input_file >> red >> green >> blue)) {
        throw std::runtime_error("Invalid color value");
      }
      if (red < 0 || red > 255 || green < 0 || green > 255 || blue < 0 ||
          blue > 255) {
        throw std::runtime_error("Invalid color value");
      }
      image[i][j].r = red;
      image[i][j].g = green;
      image[i][j].b = blue;
    }
  }

  // Check if there are too many pixel values
  if (input_file >> red) {
    throw std::runtime_error("Too many values");
  }

  printImage(image, width, height);

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
