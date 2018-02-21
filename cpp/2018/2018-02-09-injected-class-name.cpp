template <typename T1>
class A {
  template <typename T2>
  class B {
    void func(const A &);
  };
};

template<>
template<>
void A<int>::B<int>::func(const A &) {
  return;
}
