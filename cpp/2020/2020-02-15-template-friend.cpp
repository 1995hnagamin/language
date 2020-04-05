class A {
  int zero() { return 0; }
};

template <typename T>
class B {
  T zero() { return T(); }
};

class C {
  friend A;
  template <typename T>
  // friend B<T>;
  friend class B;
};
