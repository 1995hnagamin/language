#include <ff++.hpp>
#include <iostream>

double supercalifragilisticexpialidocious_hello() {
  std::cout << "Hello" << std::endl;
  return 0;
}

static void init() {
  Global.Add(
      "sayhello",
      "(",
      new OneOperator0<double>(supercalifragilisticexpialidocious_hello));
}
LOADFUNC(init);
