struct C {
  int m;
  void f() { }
};

void func() {
  new (int(*[10])());
  new float, new double, new long double;
  new bool, new char, new signed char;
  new (int C::*), new (void (C::*)());

  int i = 4;
  int *p[10];
  new int(*[i])();
}
