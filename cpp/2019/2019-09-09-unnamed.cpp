#include <iostream>

struct B {
  int i;
};

void func(B &b) {
  std::cout << "void func(B &)" << std::endl;
}

namespace {

struct C : public B {
  double d;
};

void func(C &c) {
  std::cout << "void func(C &)" << std::endl;
}

}

int main() {
  C c;
  func(c); // void func(C &)
  ::func(c); // void func(B &)
  return 0;
}
