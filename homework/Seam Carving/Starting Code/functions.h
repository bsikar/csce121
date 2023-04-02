#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <string>

using uint = unsigned int;
using ushort = unsigned short;

// struct for Pixel (short is a 2 byte signed integer)
struct Pixel {
  short r; // red
  short g; // green
  short b; // blue
};

// maximum image dimensions (do not change)
const uint MAX_WIDTH = 1920;
const uint MAX_HEIGHT = 1080;

const ushort MAX_RGB_VALUE = 255;

// already implemented
void initializeImage(Pixel image[][MAX_HEIGHT]);

void loadImage(std::string filename, Pixel image[][MAX_HEIGHT], uint &width,
               uint &height);

void outputImage(std::string filename, Pixel image[][MAX_HEIGHT], uint width,
                 uint height);
uint energy(Pixel image[][MAX_HEIGHT], uint x, uint y, uint width, uint height);

uint loadVerticalSeam(Pixel image[][MAX_HEIGHT], uint start_col, uint width,
                      uint height, uint seam[]);

uint loadHorizontalSeam(Pixel image[][MAX_HEIGHT], uint start_row, uint width,
                        uint height, uint seam[]);

void findMinVerticalSeam(Pixel image[][MAX_HEIGHT], uint width, uint height,
                         uint seam[]);

void findMinHorizontalSeam(Pixel image[][MAX_HEIGHT], uint width, uint height,
                           uint seam[]);

void removeVerticalSeam(Pixel image[][MAX_HEIGHT], uint &width, uint height,
                        uint verticalSeam[]);

void removeHorizontalSeam(Pixel image[][MAX_HEIGHT], uint width,
                          unsigned int &height, uint horizontalSeam[]);

#endif
