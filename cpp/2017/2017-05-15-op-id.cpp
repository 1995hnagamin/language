struct A {
  operator int() {
    return x;
  }
};

void func() {
  auto pf = &A::operator int;
}
