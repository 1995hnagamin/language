template<class T, T> struct S{};
template<class T> int f(S<T, T()>*) {
  return 0;
}
struct X {};

int main() {
  int i0 = f<X>(0);
}
