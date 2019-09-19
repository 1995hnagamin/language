#include <iostream>
#include <string>

extern "C" {

  struct sigaltstk {
    int foo;
    int bar;
  };

}

int sigaltstk() {
  return 1;
}

int func(int) {
  return 100;
}

int func(struct sigaltstk) {
  return 200;
}

int main() {
  auto x = sigaltstk();
  std::cout << func(x) << std::endl;

  auto y = typename struct sigaltstk();
  std::cout << func(y) << std::endl;

  return 0;
}
