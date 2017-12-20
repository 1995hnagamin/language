// ill-formed

class A {
  public:
    using Name1 = int;
    using Name2 = double;
};

template<typename Name>
A::Name func() {
  return A::Name();
}
