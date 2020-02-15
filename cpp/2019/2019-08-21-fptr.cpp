#include <iostream>
#include <string>

void func() {
  std::cout << "func\n";
  return;
}

int
main(int argc, char* argv[]) {
  (&func)();
  func();
  (*******func)();
  return 0;
}
