#include <iostream>

class A {
  public:
    void func(int x = foo) {
      std::cout << x << std::endl;
    }
  private:
    static const int foo = 42;
};

int main() {
  A a;
  a.func(); // OK, prints "42"
}
