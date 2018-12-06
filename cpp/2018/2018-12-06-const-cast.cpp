#include <iostream>
#include <string>

class A {
  public:
    std::string func() {
      return "non-const";
    }
    std::string func() const {
      return "const";
    }
};

int
main(int argc, char* argv[]) {
  A a;
  A *pa = &a;
  std::cout << pa->func() << std::endl;
  std::cout << const_cast<const A *>(pa)->func() << std::endl;
  return 0;
}
