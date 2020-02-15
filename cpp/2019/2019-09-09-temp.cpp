#include <iostream>
#include <string>

struct A {
  int i;
  template <typename T>
  bool operator <(T rhs) {
    return i < rhs.i;
  }
};


int main() {
  A a = { 1 };
  A b = { 2 };
  std::cout << (a.operator< <A>(b)) << std::endl;
}
