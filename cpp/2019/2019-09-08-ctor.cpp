class A {
  public:
    template <int I>
    A<I>(int n): i(I+n) {}
    A(): A<I>(10) {}
  private:
    int i;
};

int main() {
}
