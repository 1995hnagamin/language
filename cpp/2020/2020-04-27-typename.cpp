#include <iostream>

template<typename T>
class X {
  public:
  template<typename U>
  class Y {
    public:
    int i;
  };
  class Z {
    public:
    int j;
  };
  int k;
};

template<typename S>
void func() {
  X<S>::typename Z y;
  y.i = 100;
  std::cout << y.i << "\n";
}

int main() {
  func<int>();
}
