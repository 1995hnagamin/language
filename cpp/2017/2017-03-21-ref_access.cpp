struct A {
  int member;
};

void f() {
  A a = { 100 };
  A &ra = a;
  A *pa = &ra;
  pa->member = 200;
}
