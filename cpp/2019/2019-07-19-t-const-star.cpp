#include <iostream>

int main() {
  int const ci = 200;
  int *pi = nullptr;
  int const **ppci = nullptr;

  // std::cout << &ci << std::endl;
  // std::cout << &pi << std::endl;
  // std::cout << &ppci << std::endl;

  ppci = const_cast<int const **>(&pi);
  *ppci = &ci;
  *pi = 300;
  // std::cout << ci << std::endl;

  // int const *pci = &ci;
  // std::cout << *pci << std::endl;

  return 0;
}
