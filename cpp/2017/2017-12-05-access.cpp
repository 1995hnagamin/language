class X { };

class A : private X {
  public:
    void func(X*);
};

class B {
  friend void A::func(X*);
};

int main() {
  return 0;
}
