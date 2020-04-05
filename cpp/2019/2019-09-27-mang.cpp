namespace hoge {

extern "C" {
#include <stdio.h>
}

}

#include <iostream>

int main() {
  std::cout << 1 << std::endl;
  hoge::printf("aa\n");
  return 0;
}
