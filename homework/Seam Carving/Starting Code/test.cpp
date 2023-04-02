#include "functions.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
  // 2D array of pixels
  static Pixel image[MAX_WIDTH][MAX_HEIGHT];

  // initialize 2D array
  initializeImage(image);

  // declare variables
  string filename;
  uint width = 0;
  uint height = 0;

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

  uint s;
  cout << "enter the start_col: ";
  cin >> s;

  // call the loadVerticalSeam function
  // and print the value as well as the value in seam
  uint seam[6];
  for (uint i = 0; i < 6; i++) {
    seam[i] = 0;
  }
  uint v = loadHorizontalSeam(image, s, width, height, seam);
  cout << "value : " << v << endl;

  cout << "seam : ";
  for (uint i = 0; i < 6; i++) {
    cout << seam[i] << " ";
  }
  cout << endl;
}
