void func() {
  union {
    int i1;
    // static int i2; - error
    // typedef int *PI;
  };
}
