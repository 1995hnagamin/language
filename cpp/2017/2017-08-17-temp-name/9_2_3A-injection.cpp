#include <iostream>

int C; // #1

class C { // #2
  private:
    int i[2];
  public:
    static int f() {
      return sizeof(C); // -> #2
    }
};

int f() {
  return sizeof(C); // -> #1
}

int main() {
  std::cout << "C::f() = " << C::f() << std::endl
    << "::f() = " << ::f() << std::endl;
}
