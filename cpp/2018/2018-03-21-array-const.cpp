#include <iostream>
#include <type_traits>

int main() {
  using CI = const int;
  using A10I = int[10];
  std::cout << std::is_same<CI[10], const int[10]>::value << '\n';
  std::cout << std::is_same<const A10I, const int[10]>::value << '\n';
  std::cout << std::is_same<CI[10], const A10I>::value << '\n';
}
