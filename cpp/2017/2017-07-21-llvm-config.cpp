#include <iostream>
#include "llvm/Config/llvm-config.h"

int main() {
  std::cout << LLVM_VERSION_STRING  << std::endl;
  return 0;
}
