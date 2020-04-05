#include <string>
#include <vector>

struct A {
  operator int() {
    return 1;
  }
  operator std::vector<int>() { // OK
    std::vector<int> v;
    return v;
  }
  template <typename T>
  operator std::vector<T>() {
    std::vector<T> v;
    return v;
  }
};

int main() {
  A a;
  const auto v = static_cast<std::vector<int>>(a);
}
