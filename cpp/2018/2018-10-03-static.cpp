#include <iostream>

class klass {
  public:
    static int x;
};

int klass::x = 3;

int main() {
  klass k;
  std::cout << k.x << std::endl;
  k.x = 100;
  std::cout << klass::x << std::endl;
  return 0;
}
