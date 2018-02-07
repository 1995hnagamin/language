class B { };

class A {
  public:
  B func();
};

// B ::A::func() { return B(); } - error
// auto ::A::func() -> B { return B(); } // OK
B (::A::func)() { return B(); }
