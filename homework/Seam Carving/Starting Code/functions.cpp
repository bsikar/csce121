#include "functions.h"
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>

using std::endl;
using std::string;

void initializeImage(Pixel image[][MAX_HEIGHT]) {
  // iterate through columns
  for (uint col = 0; col < MAX_WIDTH; col++) {
    // iterate through rows
    for (uint row = 0; row < MAX_HEIGHT; row++) {
      // initialize pixel
      image[col][row] = {0, 0, 0};
    }
  }
}

void loadImage(string filename, Pixel image[][MAX_HEIGHT], uint &width,
               uint &height) {
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
  for (uint j = 0; j < height; j++) {
    for (uint i = 0; i < width; i++) {
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

void outputImage(string filename, Pixel image[][MAX_HEIGHT], uint width,
                 uint height) {
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
  for (uint j = 0; j < height; j++) {
    for (uint i = 0; i < width; i++) {
      output_file << image[i][j].r << " " << image[i][j].g << " "
                  << image[i][j].b << " ";
    }
    output_file << endl;
  }

  output_file.close();
}

uint energy(Pixel image[][MAX_HEIGHT], uint x, uint y, uint width,
            uint height) {

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

int find_min(uint l, uint m, uint r) {
  if (l == m) {
    // all are the same
    if (m == r) {
      return 0;
    }
    // middle equal to left, but middle is bias
    if (m < r) {
      return 0;
    }
    // right is the smallest
    if (m > r) {
      return 1;
    }
  }

  if (m == r) {
    // all are the same
    if (m == l) {
      return 0;
    }
    // middle equal to right, but middle is bias
    if (m < l) {
      return 0;
    }
    // left is the smallest
    if (m > l) {
      return -1;
    }
  }

  if (l == r) {
    if (m < l) {
      return 0;
    }
    return 1;
  }

  if (l < m) {
    if (l < r) {
      return -1;
    }
    return 1;
  }

  if (r < m) {
    if (l < r) {
      return -1;
    }
    return 1;
  }

  return 0;
}

uint loadVerticalSeam(Pixel image[][MAX_HEIGHT], uint start_col, uint width,
                      uint height, uint seam[]) {
  // start at the first row, but the correct col
  uint curr_value = energy(image, start_col, 0, width, height);
  seam[0] = start_col;

  for (uint i = 1; i < height; i++) {
    int min_index;

    // check the bounds
    if (start_col == 0) {
      uint mid = energy(image, start_col, i, width, height);
      uint right = energy(image, start_col + 1, i, width, height);

      // since there are only 2 values so we are going to
      // set the other one to max
      // ~0u means bitwise not (~) on 0u and 0u is 0, but the u makes
      // the compiler know that it should be treated as unsigned
      int dir_change = find_min(~0u, mid, right);
      min_index = start_col + dir_change;
      start_col += dir_change;
    } else if (start_col == width - 1) {
      uint left = energy(image, start_col - 1, i, width, height);
      uint mid = energy(image, start_col, i, width, height);

      int dir_change = find_min(left, mid, ~0u);
      min_index = start_col + dir_change;
      start_col += dir_change;
    } else {
      uint left = energy(image, start_col - 1, i, width, height);
      uint mid = energy(image, start_col, i, width, height);
      uint right = energy(image, start_col + 1, i, width, height);

      int dir_change = find_min(left, mid, right);
      min_index = start_col + dir_change;
      start_col += dir_change;
    }

    // update the current value
    curr_value += energy(image, min_index, i, width, height);
    // update the seam
    seam[i] = min_index;
  }

  return curr_value;
}

// TODO: XXX: FIXME: THIS DOES NOT WORK HEHEHE
uint loadHorizontalSeam(Pixel image[][MAX_HEIGHT], uint start_row, uint width,
                        uint height, uint seam[]) {
  // start at the first col, but the correct row
  uint curr_value = energy(image, 0, start_row, width, height);
  seam[0] = start_row;

  for (uint i = 1; i < width; i++) {
    int min_index;

    // check the bounds
    if (start_row == 0) {
      uint mid = energy(image, i, start_row, width, height);
      uint right = energy(image, i, start_row + 1, width, height);

      // since there are only 2 values so we are going to
      // set the other one to max
      // ~0u means bitwise not (~) on 0u and 0u is 0, but the u makes
      // the compiler know that it should be treated as unsigned
      int dir_change = find_min(~0u, mid, right);
      min_index = start_row + dir_change;
      start_row += dir_change;
    } else if (start_row == height - 1) {
      uint left = energy(image, i, start_row - 1, width, height);
      uint mid = energy(image, i, start_row, width, height);

      int dir_change = find_min(left, mid, ~0u);
      min_index = start_row + dir_change;
      start_row += dir_change;
    } else {
      uint left = energy(image, i, start_row - 1, width, height);
      uint mid = energy(image, i, start_row, width, height);
      uint right = energy(image, i, start_row + 1, width, height);

      int dir_change = find_min(left, mid, right);
      min_index = start_row + dir_change;
      start_row += dir_change;
    }

    // update the current value
    curr_value += energy(image, i, min_index, width, height);
    // update the seam
    seam[i] = min_index;
  }

  return curr_value;
}

void findMinVerticalSeam(Pixel image[][MAX_HEIGHT], uint width, uint height,
                         uint seam[]) {
  uint min = loadVerticalSeam(image, 0, width, height, seam);
  uint min_index = 0;
  for (uint i = 1; i < width; i++) {
    uint tmp = loadVerticalSeam(image, i, width, height, seam);
    if (tmp < min) {
      min_index = i;
      min = tmp;
    }
  }
  loadVerticalSeam(image, min_index, width, height, seam);
}

// TODO: XXX: FIXME DOES NOT WORK AT ALL :(
void findMinHorizontalSeam(Pixel image[][MAX_HEIGHT], uint width, uint height,
                           uint seam[]) {
  uint min = loadHorizontalSeam(image, 0, width, height, seam);
  uint min_index = 0;
  for (uint i = 1; i < height; i++) {
    uint tmp = loadHorizontalSeam(image, i, width, height, seam);
    if (tmp < min) {
      min_index = i;
      min = tmp;
    }
  }
  loadHorizontalSeam(image, min_index, width, height, seam);
}

void removeVerticalSeam(Pixel image[][MAX_HEIGHT], uint &width, uint height,
                        uint verticalSeam[]) {
  for (uint i = 0; i < height; i++) {
    uint col = verticalSeam[i];
    for (uint j = col; j < width - 1; j++) {
      image[j][i] = image[j + 1][i];
    }
  }
  width -= 1;
}

void removeHorizontalSeam(Pixel image[][MAX_HEIGHT], uint width, uint &height,
                          uint horizontalSeam[]) {
  for (uint i = 0; i < width; i++) {
    uint row = horizontalSeam[i];
    for (uint j = row; j < height - 1; j++) {
      image[i][j] = image[i][j + 1];
    }
  }
  height -= 1;
}
