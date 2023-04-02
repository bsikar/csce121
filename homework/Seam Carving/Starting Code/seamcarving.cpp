#include "functions.h"
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>

using std::cout, std::endl, std::cin, std::string, std::stringstream;

int main() {
  // 2D array of pixels
  static Pixel image[MAX_WIDTH][MAX_HEIGHT];

  // initialize 2D array
  initializeImage(image);

  // declare variables
  string filename;
  uint width = 0;
  uint height = 0;
  int targetWidth = 0;
  int targetHeight = 0;

  // accept filename
  cout << "Input filename: ";
  cin >> filename;

  try {
    // attempt to load image
    loadImage(filename, image, width, height);
    cout << "Detected image width: " << width << endl;
    cout << "Detected image height: " << height << endl;
  } catch (std::exception &ex) {
    cout << "Exception thrown: " << ex.what() << endl;
    return 1; // exit with error
  }

  // accept target dimensions
  cout << "Input target width: ";
  cin >> targetWidth;
  cout << "Input target height: ";
  cin >> targetHeight;

  // Exit program with error if there are problems with
  //   targetWidth or targetHeight
  if (targetWidth > static_cast<int>(width) ||
      targetHeight > static_cast<int>(height)) {
    cout << "Invalid target dimensions" << endl;
    return 1;
  }

  cout << "Start carving..." << endl;

  while ((width - targetWidth > 0) || (height - targetHeight > 0)) {
    // find and remove a vertical seam
    if (width - targetWidth > 0) {
      uint verticalSeam[MAX_HEIGHT];
      findMinVerticalSeam(image, width, height, verticalSeam);
      removeVerticalSeam(image, width, height, verticalSeam);
    }
    // this is for the extra credit
    // find and remove a horizontal seam
    if (height - targetHeight > 0) {
      uint horizontalSeam[MAX_WIDTH];
      findMinHorizontalSeam(image, width, height, horizontalSeam);
      removeHorizontalSeam(image, width, height, horizontalSeam);
    }
  }

  try {
    // attempt to output image
    stringstream ss;
    ss << "carved" << width << "X" << height << ".ppm";
    outputImage(ss.str().c_str(), image, width, height);
  } catch (std::exception &ex) {
    cout << "Exception thrown: " << ex.what() << endl;
    return 1; // exit with an error
  }

  cout << "Image output" << endl;

  return 0; // exit without errors
}
