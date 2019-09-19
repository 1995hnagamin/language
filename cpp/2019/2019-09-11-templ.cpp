template <typename T>
auto func(T, T) -> T;

template <typename T>
auto func(T x, T y) -> T {
  return x + y;
}

template <>
auto func(int, int) -> int {
  return 0;
}
