#include <ff++.hpp>
#include <iostream>

double print_hello() {
  std::cout << "Hello" << std::endl;
  return 0;
}

static void init() {
  Global.Add(
      "sayhello",
      "(",
      new OneOperator0<double>(print_hello));
}
LOADFUNC(init);
