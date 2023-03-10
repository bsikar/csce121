#include "functions.h"
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>

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

void loadImage(string filename, Pixel image[][MAX_HEIGHT], unsigned int &width,
               unsigned int &height) {
  std::ifstream input_file(filename);

  if (!input_file) {
    throw std::runtime_error("Failed to open " + filename);
  }

  // read in the PPM header information
  string line;
  int maxColorValue;
  input_file >> line >> width >> height >> maxColorValue;

  // validate the header information
  if (line != "P3" && line != "p3") {
    throw std::runtime_error("Invalid type " + line);
  }
  if (width <= 0 || height <= 0 || width > MAX_WIDTH || height > MAX_HEIGHT) {
    throw std::runtime_error("Invalid dimensions");
  }
  if (maxColorValue != MAX_RGB_VALUE) {
    throw std::runtime_error("Invalid color value");
  }

  // read in the pixel values
  int rgb[3];
  for (unsigned int j = 0; j < height; j++) {
    for (unsigned int i = 0; i < width; i++) {
      // check valid input
      if (!(input_file >> rgb[0] >> rgb[1] >> rgb[2])) {
        throw std::runtime_error("Invalid color value");
      }

      // check the bounds
      for (int k = 0; k < 3; k++) {
        if (rgb[k] < 0 || rgb[k] > MAX_RGB_VALUE) {
          throw std::runtime_error("Invalid color value");
        }
      }
      // set values
      image[i][j].r = rgb[0];
      image[i][j].g = rgb[1];
      image[i][j].b = rgb[2];
    }
  }

  // check if there are too many pixel values
  if (input_file >> rgb[0]) {
    throw std::runtime_error("Too many values");
  }

  input_file.close();
}

void outputImage(string filename, Pixel image[][MAX_HEIGHT], unsigned int width,
                 unsigned int height) {
  std::ofstream output_file(filename);

  // check for error
  if (!output_file) {
    throw std::runtime_error("Failed to open " + filename);
  }

  // add header
  output_file << "P3" << endl;

  // add dimensions
  output_file << width << " " << height << endl;

  // add max rgb value
  output_file << MAX_RGB_VALUE << endl;

  // write to a file
  for (unsigned int j = 0; j < height; j++) {
    for (unsigned int i = 0; i < width; i++) {
      output_file << image[i][j].r << " " << image[i][j].g << " "
                  << image[i][j].b << " ";
    }
    output_file << endl;
  }

  output_file.close();
}

unsigned int energy(Pixel image[][MAX_HEIGHT], unsigned int x, unsigned int y,
                    unsigned int width, unsigned int height) {

  int up[2], down[2], left[2], right[2];

  if (x == 0) {
    up[0] = width - 1;
    up[1] = y;
  } else {
    up[0] = x - 1;
    up[1] = y;
  }

  if (x == width - 1) {
    down[0] = 0;
    down[1] = y;
  } else {
    down[0] = x + 1;
    down[1] = y;
  }

  if (y == 0) {
    left[0] = x;
    left[1] = height - 1;
  } else {
    left[0] = x;
    left[1] = y - 1;
  }

  if (y == height - 1) {
    right[0] = x;
    right[1] = 0;
  } else {
    right[0] = x;
    right[1] = y + 1;
  }

  int red = image[up[0]][up[1]].r - image[down[0]][down[1]].r;
  int green = image[up[0]][up[1]].g - image[down[0]][down[1]].g;
  int blue = image[up[0]][up[1]].b - image[down[0]][down[1]].b;

  int red2 = image[left[0]][left[1]].r - image[right[0]][right[1]].r;
  int green2 = image[left[0]][left[1]].g - image[right[0]][right[1]].g;
  int blue2 = image[left[0]][left[1]].b - image[right[0]][right[1]].b;

  int energy = (red * red) + (green * green) + (blue * blue) + (red2 * red2) +
               (green2 * green2) + (blue2 * blue2);

  return energy;
}
// uncomment functions as you implement them (part 2)

// unsigned int loadVerticalSeam(Pixel image[][MAX_HEIGHT], unsigned int
// start_col, unsigned int width, unsigned int height, unsigned int seam[])
// {
//   // TODO: implement (part 2)
//   return 0;
// }

// unsigned int loadHorizontalSeam(Pixel image[][MAX_HEIGHT], unsigned int
// start_row, unsigned int width, unsigned int height, unsigned int seam[])
// {
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
