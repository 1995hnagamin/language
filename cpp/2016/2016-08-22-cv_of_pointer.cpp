void f() {
  const volatile int *cvpi = 0;
  int * const volatile picv = 0;
  const volatile int * const volatile cvpicv = 0;

  int (*f1)() = 0;
  int (* const f2)() = 0;
}

void g() {
  void (*fp1)() = f;
  fp1 = g;
  void (* const fp2)() = f;
  //fp2 = g;
}
