#include <vector>
#include <iostream>
#include "library.hpp"

int main() {
  Point3D<int> o = origin();
  std::cout << o.accumulate() << std::endl;
  return 0;
}
