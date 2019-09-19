#include <iostream>

union U1 {
  int i;
  double d;
};

int main() {
  U1 *u = new U1();
  std::cout << u->i << std::endl;
  return 0;
}
