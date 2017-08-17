template<typename T>
class C {
  friend void f();
  friend void f(C<T> const&);
};

void g(C<int> *p) {
  // f(); - error
  f(*p);
}
