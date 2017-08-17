class A {
  public:
    int x;
  template<typename T>
  void func(T const&) { }
};

int main() {
  A a;
  a.template func(a);
}
