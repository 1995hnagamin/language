#include <iostream>
#include <string>

class A {
  public:
    int a;
    ~A() = delete; // OK, a destructor can be defined as deleted
};

int
main(int argc, char* argv[]) {
  // A a; - error, use of a deleted function
  return 0;
}
