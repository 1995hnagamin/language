int x;

class B {
  public:
    int i;
};

class D : public B { };

void f(D *pd) {
  pd->i = 3;
  // D::x = 2;
}
