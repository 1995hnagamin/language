#include <iostream>

template <typename T>
class klass1 {
  public:
    void func() {
      std::cout << "klass1<T>::func" << std::endl;
    }
};

using T1 = int;

class klass2 : klass1<T1> {
  public:
    void func() {
      std::cout << "klass2::func" << std::endl;
    }
    void call_func(klass2 other) {
      other.klass1<T1>::func();
    }
};
