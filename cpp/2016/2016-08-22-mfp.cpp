class A {
public:
  int cf() const;
  int f();
};

void f() {
  int (A::*pfc)() const = &A::cf;
  pfc = &A::f;
  int (A::*pf)() = &A::f;
  pf = &A::cf;
}
