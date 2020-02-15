template <template <class> class Temp>
class A {
  public:
    Temp<int> ti;
};

template <typename T>
class Pair {
  public:
    T t1;
    T t2;
};

int main() {
  A<Pair> ap;
  ap.ti.t1 = 100;
  return 0;
}
