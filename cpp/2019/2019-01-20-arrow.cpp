#include <iostream>
#include <string>
#include <vector>

int
main(int argc, char* argv[]) {
  std::vector<std::string> vs(10, "foo");
  std::vector<std::string> *pvs = &vs;
  std::cout << pvs->operator[](0) << std::endl;
  return 0;
}
