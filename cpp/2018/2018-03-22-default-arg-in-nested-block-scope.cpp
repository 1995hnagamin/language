#include <iostream>

void func(int a, int b) {
  std::cout << a+b << std::endl;
}

int main() {
  void func(int a, int b = 10);
  func(10); // "20"
  // void func(int a, int b = 20); - error
  {
    func(10); // "20"
    void func(int a, int b = 30); // OK
    func(10); // "40"
  }
}
