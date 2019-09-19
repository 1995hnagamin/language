namespace A {
  class Klass {
    public:
    explicit Klass(): i(100) {
    }
    int i;
  };
}

int main() {
  using namespace A;
  auto const k = Klass();
  ::A::Klass x;
  return 0;
}
