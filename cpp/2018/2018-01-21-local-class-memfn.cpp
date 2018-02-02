#include <functional>
#include <iostream>
using namespace std;

int main() {
  int value = 10;
  struct A {
    const std::function<int()> f = [=]() -> int {
      return value;
    };
  };
  A a;
  cout << a.f() << endl;
  return 0;
}
