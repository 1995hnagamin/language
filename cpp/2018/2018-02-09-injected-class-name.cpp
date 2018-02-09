template <typename T1>
class A {
  template <typename T2>
  class B {
    void func(const A &);
  };
};
