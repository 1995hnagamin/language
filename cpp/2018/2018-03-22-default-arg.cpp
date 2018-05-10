#include <iostream>

int y = 0;

void func(int x = y) {
  return x;
}

int main() {
  int y = 42;
  std::cout << func(y) << std::endl;
  std::cout << func() << std::endl;
  ::y = 1000;
  std::cout << func() << std::endl;
}
