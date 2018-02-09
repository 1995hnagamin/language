class A {
  protected:
    int x;
};

class B : public A {
  public:
    using A::x;
};

int main() {
  B obj;
  // obj.::A::x; - error
  obj.::B::x; // OK
  return 0;
}
