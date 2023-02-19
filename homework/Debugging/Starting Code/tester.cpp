#include "functions.h"
#include <iostream>
#include <tuple>

int edge() {
  std::tuple<int, int> okay_inputs[] = {
      {-2147483648, 2147483647}, {-2147483648, -2147483648},
      {2147483647, 2147483647},  {-2147483647, 2147483647},
      {-2147483646, 2147483647}, {-2147483647, 2147483646}};
  int okay_outputs[] = {
      INT32_MIN, -2147483648, 2147483647, 0, 2147483647, -2147483647,
  };

  for (int i = 0; i < 6; i++) {
    auto input = okay_inputs[i];
    int a = std::get<0>(input);
    int b = std::get<1>(input);
    try {
      int output = SumBetween(a, b);

      if (output != okay_outputs[i]) {
        std::cout << "wrong" << std::endl;
        std::cout << "inputs: " << a << " " << b << std::endl;
        std::cout << "expected " << okay_outputs[i] << " got " << output
                  << std::endl;
        return 1;
      }

    } catch (...) {
      std::cout << "unexpected throw" << std::endl;
      std::cout << "wrong" << std::endl;
      std::cout << "inputs: " << a << " " << b << std::endl;
      std::cout << "expected " << okay_outputs[i] << std::endl;
      return 1;
    }
  }

  std::tuple<int, int> bad_inputs[] = {{0, 2147483647}, {-2147483648, 0}};
  for (int i = 0; i < 2; i++) {
    auto input = bad_inputs[i];
    int a = std::get<0>(input);
    int b = std::get<1>(input);
    try {
      SumBetween(a, b);
      std::cout << "expected throw" << std::endl;
      std::cout << "wrong" << std::endl;
      std::cout << "inputs: " << a << " " << b << std::endl;
      return 1;
    } catch (...) {
    }
  }

  return 0;
}

int unhappy() {
  std::tuple<int, int> inputs[] = {
      {-104565, 78382}, {-126478, -1109}, {78340, 124101},  {-80910, 130786},
      {-69527, -2738},  {-12345678, 0},   {0, 8765432},     {-47333, -98438},
      {22365, -81043},  {116881, 19066},  {106695, -53113}, {79155, -6694},
      {-56121, -93515}, {112638, 20481}};
  for (auto input : inputs) {
    int a = std::get<0>(input);
    int b = std::get<1>(input);
    try {
      SumBetween(a, b);

      std::cout << "expected throw" << std::endl;
      std::cout << "SumBetween(" << a << ", " << b << ")" << std::endl;
      std::cout << "Found: " << SumBetween(a, b) << std::endl;
      return 1;
    } catch (...) {
    }
  }
  return 0;
}

int happy() {
  std::tuple<int, int> inputs[] = {
      {1, 10},         {32581, 57929},  {28402, 31178},  {-73440, -60964},
      {-7746, 11488},  {-80021, 80542}, {-39609, 56109}, {-81956, 95369},
      {-67944, 87969}, {-99, 0},        {0, 4165},
  };

  int outputs[] = {55,         1147168995, 82726830,  -838479354,
                   35988685,   41826922,   789681750, 1189236819,
                   1561088925, -4950,      8675695};

  for (int i = 0; i < 11; i++) {
    auto input = inputs[i];
    int a = std::get<0>(input);
    int b = std::get<1>(input);
    try {
      int output = SumBetween(a, b);

      if (output != outputs[i]) {
        std::cout << "wrong" << std::endl;
        std::cout << "inputs: " << a << " " << b << std::endl;
        std::cout << "expected " << outputs[i] << " got " << output
                  << std::endl;
        return 1;
      }

    } catch (...) {
      std::cout << "unexpected throw" << std::endl;
      std::cout << "wrong" << std::endl;
      std::cout << "inputs: " << a << " " << b << std::endl;
      std::cout << "expected " << outputs[i] << std::endl;
      return 1;
    }
  }
  return 0;
}

int main() {
  bool unhappy_result = unhappy();
  if (unhappy_result) {
    std::cout << "unhappy failed" << std::endl;
    return 1;
  } else {
    std::cout << "unhappy passed" << std::endl;
  }

  bool happy_result = happy();
  if (happy_result) {
    std::cout << "happy failed" << std::endl;
    return 1;
  } else {
    std::cout << "happy passed" << std::endl;
  }

  bool edge_result = edge();
  if (edge_result) {
    std::cout << "edge failed" << std::endl;
    return 1;
  } else {
    std::cout << "edge passed" << std::endl;
  }
}
