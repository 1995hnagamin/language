#include <iostream>

void func(int a, int b) {
  std::cout << a+b << std::endl;
}

int main() {
  const int i = 100;
  extern void func(int a, int b = i); // error
  for (int i = 1; i < 10; ++i) {
    func(i);
  }
}
