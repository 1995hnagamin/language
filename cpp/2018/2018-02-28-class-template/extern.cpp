template <typename T> struct Id {
  T x;
  T id();
};

template <typename T> T Id<T>::id() { return x; }

extern template struct Id<int>;

int dummy(int x) {
  Id<int> o;
  o.x = 1;
  return o.id();
}
