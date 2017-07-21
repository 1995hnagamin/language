int f(int x) {
  return 42;
}

template<typename T>
T f(T x) {
  auto func = f;
  return (x > 0 ? x * func(x - 1) : 1);
}

int main() {
  int x = f(5);
}
