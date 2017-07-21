namespace A {
  struct B {};
  template<typename T> void f(T) {
  }
}

void g(A::B b) {
  //f<A::B>(b); ill-formed, fが見つからないので< > がテンプレートの文法とみなされない
  template f(b); // OK, ADLでfが見つかる
}
