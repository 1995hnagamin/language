#include <iostream>
#include <string>

int to_int(char c) {
  return (int)c;
}

int
main(int argc, char* argv[]) {
  auto (*func1)(char) -> int = to_int; // OK
  std::cout << (*func1)('a') << std::endl;
  // auto func2(char) -> int = to_int; // error
  return 0;
}
