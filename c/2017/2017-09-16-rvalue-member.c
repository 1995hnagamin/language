struct Foo {
  int i;
};

struct Foo func() {
  struct Foo foo;
  foo.i = 100;
  return foo;
}

int main() {
  int k = func().i;
  return 0;
}
