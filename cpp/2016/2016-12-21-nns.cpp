namespace A {
  namespace B {
    namespace C {
      int x;
    }
  }
}

int f() {
  return ::A::B::C::x;
}
