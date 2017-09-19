#include <iostream>

void show(int *arr, size_t size) {
  for (size_t i = 0; i < size; ++i) {
    if (i > 0) { std::cout << ","; }
    std::cout << arr[i];
  }
  std::cout << std::endl;
}

int main() {
  size_t N = 3;
  int *pi = new int[N] {1, 2, 3}; // list-initialization
  show(pi, N);  delete[] pi;

  int *pi2 = new int[N]{};        // list-initialization
  show(pi2, N);  delete[] pi2;

  int *pi3 = new int[N]();
  show(pi3, N);  delete[] pi3;    // value-initialization

  int *pi4 = new int[N];
  show(pi4, N);  delete[] pi4;    // default-initialization

  // int *pi5 = new int[N]({1, 2, 3}) - error

  int *pi6 = new int[N];
  return 0;
}
