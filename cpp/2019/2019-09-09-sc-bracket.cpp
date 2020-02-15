#include <iostream>
#include <vector>

int main() {
  auto v = static_cast<std::vector<int>>(2);
  v[0] = v[1] = 100;
  for (auto &&x : v) {
    std::cout << x << "\n";
  }
}
