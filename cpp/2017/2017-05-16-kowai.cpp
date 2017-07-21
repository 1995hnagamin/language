namespace X {
  template<typename T>
  class hoge {
    public:
    hoge() = default;
  };
}

namespace Y {
  template<typename T>
  class hunya {
  };
}

namespace Z {
  class honyarara { };
}

class A {
  public:
  operator X::hoge<Y::hunya<Z::honyarara>>() {
    return X::hoge<Y::hunya<Z::honyarara>>();
  }
};

int main() {
  A a;
  A* pa = &a;
  a.operator X::hoge<Y::hunya<Z::honyarara>>();
  pa->operator X::hoge<Y::hunya<Z::honyarara>>();
  return 0;
}
