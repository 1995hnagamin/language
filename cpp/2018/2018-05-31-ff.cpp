#include <iomanip>
#include <iostream>
#include <string>

int
main() {
  std::cout << std::hex;
  std::cout << "x |";
  for (int idx = 0x1; idx < 0x10; ++idx) {
    std::cout << std::setfill(' ') << std::setw(2) << idx << ' ';
  }
  std::cout << '\n' << "--+" << std::string(3*0xf, '-') << '\n';

  for (int i = 0x1; i < 0x10; ++i) {
    std::cout << std::setfill(' ') << std::setw(2) << i << '|';
    for (int j = 0x1; j < 0x10; ++j) {
      std::cout << std::setfill(' ') << std::setw(2) << i*j << ' ';
    }
    std::cout << '\n';
  }
  return 0;
}
