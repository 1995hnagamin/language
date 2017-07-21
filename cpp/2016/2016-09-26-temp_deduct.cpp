namespace S14_8_2_1_1 {
  template<typename T>
  struct S1 {
    int f(T) { return 0; }
  };

  template<typename T>
  struct S2 {
    T f(T t) { return t; }
  };

  int main() {
    S1<void> a;     // function parameter cannot have a type of void
    S2<int()> b;    // function cannot return function type value
    S2<int[10]> c;  // function cannot return array type value
  }
}

namespace S14_8_2_1_3 {
  template <class T> int f(T&&);
  int main() {
    int i = 0;
    int n1 = f(i);
  }
}
