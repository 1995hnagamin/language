#include <ff++.hpp>
#include <iostream>

double supercalifragilisticexpialidocious_hello() {
  std::cout << "hello" << std::endl;
  return 0;
}

static void init() {
  Global.Add(
      "supercalifragilisticexpialidocious",
      "(",
      new OneOperator0<double>(supercalifragilisticexpialidocious_hello));
}
LOADFUNC(init);
