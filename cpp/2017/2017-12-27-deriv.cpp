#include <iostream>

class Base { };

class A : private Base {
  public:
    class Base { };
    int func(const ::Base&) {
      return 10;
    }
    int func(const A::Base&) {
      return 20;
    }
};

int main() {
  Base base;
  A a;
  A::Base a_base;
  std::cout << a.func(base)   << std::endl;
  std::cout << a.func(a_base) << std::endl;
  return 0;
}
