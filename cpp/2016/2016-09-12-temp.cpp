template<typename T>
class A {
  void f() { }
};

template<>
inline void A<int>::f() {}
