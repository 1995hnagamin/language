class A {};

void f(A&& a) {
}

void g() {
  A a;
  f(a);
}
