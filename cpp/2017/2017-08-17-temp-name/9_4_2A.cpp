template<typename X>
class Base {
  public:
    int basefield;
    typedef int T; // #1
};

template<typename T>
class DD : public Base<T> {
  public:
    void f() { this->basefield = 0; }
};


template<>
class Base<bool> {
  public:
    int const basefield = 42;
};

void g(DD<bool> &d) {
  d.f();
}
