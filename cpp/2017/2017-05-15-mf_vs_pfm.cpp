//#include <iostream>

struct Obj {
  void (*ptr_to_fn)(int, int);
  void mem_fn(int, int) {
    // std::cout << "void mem_fn(int, int)" << std::endl;
  }
};

void func(int, int) {
  // std::cout << "void func(int, int)" << std::endl;
}

int main() {
  Obj obj;
  obj.ptr_to_fn = func;
  obj.ptr_to_fn(1, 2);
  obj.mem_fn(1, 2);
  return 0;
}
