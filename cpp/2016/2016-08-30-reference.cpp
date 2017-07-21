struct A {
  int x;
};

void f(A const & r, A const * p) {
  int i = r.x;
  int j = p->x;
}
