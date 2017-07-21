class A;

void func(A*) {
}

class A {
public:
  void (* const f)(A*) = func;
};
