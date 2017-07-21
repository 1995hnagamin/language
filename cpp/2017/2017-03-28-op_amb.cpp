#include <iostream>

namespace N {
  namespace {
    class A {
      public:
      void operator+(const A&) {
        std::cout << "N::( )::A::operator+" << std::endl;
      }
    };
    void operator+(const A&, const A&) {
      std::cout << "N::( )::operator+" << std::endl;
    }
  }
  void operator+(const A&, const A&) {
    std::cout << "N::operator+" << std::endl;
  }
}

void main2();

int main() {
  std::cout << "= main =" << std::endl;
  N::A a;
  a + a;
  operator+(a, a);
  N::operator+(a, a);
  main2();
  return 0;
}

void main2() {
  std::cout << "= main2 =" << std::endl;
  using namespace N;
  A a;
  a + a;
  // operator+(a, a); - error
  N::operator+(a, a);
}
