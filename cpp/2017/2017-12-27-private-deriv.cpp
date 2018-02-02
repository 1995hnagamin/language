class Base {
  public:
    int get_number() const {
      return 42;
    }
};

class A : private Base {
  public:
    int func(Base *);
};

class B {
  public:
 // friend void A::func(  Base *); error
    friend int A::func(::Base *); // OK
};

int A::func(Base *) {
  return get_number();
}

int main() {
  B b;

  return 0;
}
