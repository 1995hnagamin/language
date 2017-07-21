#include <iostream>

template<typename T> void f(T&) {
  std::cout << "#1" << std::endl;
}

template<typename T> void f(T&&) {
  std::cout << "#2" << std::endl;
}

template<typename T> void f(const T&) {
  std::cout << "#3" << std::endl;
}

template<typename T> void f(const T&&) {
  std::cout << "#4" << std::endl;
}

int main() {
  int x;
  f(x);
  f(std::move(x));
  f(2);
}
