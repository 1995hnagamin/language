#include <vector>
#include <iostream>

void f1() {
  std::vector<int>&& a = {1, 2, 3};
  std::vector<int>&& b {1, 2, 3};
  std::vector<int>&& c({1, 2, 3});
  const std::vector<int>& d({1, 2, 3});
  std::vector<int>& e = a;
}


void f2() {
  int&& a = 1;
  int& b = a;
  b = 100;
  std::cout << a << std::endl;
}

void f3() {
  int&& a = 1;
  int&& b = std::move(a);
  b = 100;
  std::cout << a << std::endl;
}

int main() {
  f2();
  f3();
}
