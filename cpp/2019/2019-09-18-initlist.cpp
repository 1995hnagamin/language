#include <iostream>
#include <string>

int
main() {
  std::initializer_list<std::string> ils = { "sunday", "monday", "tuesday" };
  for (auto &&s : ils) {
    std::cout << s << std::endl;
  }
  return 0;
}
