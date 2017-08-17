template<typename X>
class Base {
  public:
    int basefield;
    typedef int T; // #1
};

class D1 : public Base< Base<void> > {
  public:
    void f() { basefield = 3; }
};

template<typename T> // #2
class D2 : public Base<double> {
  public:
    void f() { basefield = 7; }
    T strange; // #1
};

void g(D2<int*> &d2, int *p) {
  // d2.strange = p; - error
}
