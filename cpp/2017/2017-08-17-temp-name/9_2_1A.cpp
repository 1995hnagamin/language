#include <iostream>

namespace X {

template<typename T>
void f(T);

} // namespace X

namespace N {

using namespace X;

enum E { e1 };

void f(E) { // #1
  std::cout << "N::f(N::E) called" << std::endl;
}

} // namespace N

void f(int) { // #2
  std::cout << "::f(int) called" << std::endl;
}

int main() {
  ::f(N::e1); // #2
  f(N::e1); // #1 (ADL)
}
