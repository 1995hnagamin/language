class Base {
};

class A : private Base {
  public:
    void func(Base *);
};

class B {
  public:
 // friend void A::func(  Base *); error
    friend void A::func(::Base *); // OK
};

int main() {
  return 0;
}
