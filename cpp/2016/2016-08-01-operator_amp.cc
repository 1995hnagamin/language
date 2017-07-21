#include <utility>
#include <iostream>

namespace A {
  void main_proc() {
    int x = 1, y = 2;
    std::swap(x, y);
    std::cout << x << y << std::endl;
  }
}

namespace B {
  class myInt {
  public:
    class Ref {
    public:
      Ref(myInt *p): ptr(p) {}
      myInt *ptr;
    };

    myInt(int n): num(n) {}
    Ref operator&() {
      return Ref(this);
    }

    int num;
  };

  void swap(myInt::Ref x, myInt::Ref y) {
    std::swap(*x.ptr, *y.ptr);
  }

  void main_proc() {
    myInt x = 1, y = 2;
    swap(&x, &y);
    std::cout << x.num << y.num << std::endl;
  }
}

int main() {
  A::main_proc();
  B::main_proc();
}
