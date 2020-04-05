#include <iostream>
#include <string>

class A { };

class B { };

class X {
public:
  A a;
  B b;
  int i;
};

int main() {
  std::cout << std::hex;

  X x;
  std::cout
    << &x << '\n'
    << &(x.a) << '\n'
    << &(x.b) << '\n'
    << &(x.i) << '\n';
  return 0;
}
