template <typename T>
T func() {
  T val(1, 2, 3);
  return val;
};

struct A {
  A(int i, int j, int k): x(i+j+k) {
  }
  int x;
};

int main() {
  A a = func<A>();
  return 0;
}
