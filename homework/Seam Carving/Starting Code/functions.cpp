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

  printImage(image, width, height);

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
  for (unsigned int i = 0; i < width; i++) {
    for (unsigned int j = 0; j < height; j++) {
      output_file << image[i][j].r << " " << image[i][j].g << " "
                  << image[i][j].b << " ";
    }
    output_file << endl;
  }

  output_file.close();
}

unsigned int energy(Pixel image[][MAX_HEIGHT], unsigned int x, unsigned int y,
                    unsigned int width, unsigned int height) {

  // loop through every pixel
  Pixel p_left, p_right, p_top, p_bottom;
  int x_l, x_r, x_t, x_b;
  int y_l, y_r, y_t, y_b;
  // There are 5 cases, TL, TR, BL, BR, R

  // TL
  if (x == 0 && y == 0) {
    cout << "CASE TL" << endl;
    x_l = width - 1;
    x_r = x + 1;
    x_t = x;
    x_b = x;

    y_l = y;
    y_r = y;
    y_b = y + 1;
    y_t = height - 1;
  }

  // TR
  else if (x == 0 && y == height - 1) {
    cout << "CASE TR" << endl;
    x_l = x - 1;
    x_r = 0;
    x_t = x;
    x_b = x;

    y_l = y;
    y_r = y;
    y_t = height - 1;
    y_b = y + 1;
  }

  // BL
  else if (x == 0 && y == height - 1) {
    cout << "CASE BL" << endl;
    x_l = width - 1;
    x_r = x + 1;
    x_t = x;
    x_b = x;

    y_l = y;
    y_r = y;
    y_t = y - 1;
    y_b = 0;
  }

  // BR
  else if (x == width - 1 && y == height - 1) {
    cout << "CASE BR" << endl;
    x_l = x - 1;
    x_r = 0;
    x_t = x;
    x_b = x;

    y_l = y;
    y_r = y;
    y_t = y - 1;
    y_b = 0;
  }

  // R
  else {
    cout << "CASE R" << endl;
    cout << "(starting): ( " << x << ", " << y << " )" << endl;
    x_l = x - 1;
    x_r = x + 1;
    x_t = x;
    x_b = x;

    y_l = y;
    y_r = y;
    y_t = y - 1;
    y_b = y + 1;
    cout << "(left): ( " << x_l << ", " << y_l << " )" << endl;
    cout << "(right): ( " << x_r << ", " << y_r << " )" << endl;
    cout << "(top): ( " << x_t << ", " << y_t << " )" << endl;
    cout << "(bottom): ( " << x_b << ", " << y_b << " )" << endl;

    printImage(image, width, height);
  }

  //  p_left = image[y_l][x_l];
  //  p_right = image[y_r][x_r];
  //  p_top = image[y_t][x_t];
  //  p_bottom = image[y_b][x_b];
  //
  p_left = image[x_l][y_l];
  p_right = image[x_r][y_r];
  p_top = image[x_t][y_t];
  p_bottom = image[x_b][y_b];

  // find the energy of the left, right pixels
  int deltas[3];

  cout << endl << endl;
  deltas[0] = p_right.r - p_left.r;

  cout << "Rx(" << x << ", " << y << ") = " << p_right.r << " - " << p_left.r
       << " = " << deltas[0] << endl;

  deltas[1] = p_right.g - p_left.g;

  cout << "Gx(" << x << ", " << y << ") = " << p_right.g << " - " << p_left.g
       << " = " << deltas[1] << endl;

  deltas[2] = p_right.b - p_left.b;
  cout << "Bx(" << x << ", " << y << ") = " << p_right.g << " - " << p_left.b
       << " = " << deltas[2] << endl;

  int energies[2];

  energies[0] = (deltas[0] * deltas[0]) + (deltas[1] * deltas[1]) +
                (deltas[2] * deltas[2]);

  // find the energy of the top and bottom pixels
  deltas[0] = p_bottom.r - p_top.r;
  deltas[1] = p_bottom.g - p_top.g;
  deltas[2] = p_bottom.b - p_top.b;

  energies[1] = (deltas[0] * deltas[0]) + (deltas[1] * deltas[1]) +
                (deltas[2] * deltas[2]);

  return energies[0] + energies[1];
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
