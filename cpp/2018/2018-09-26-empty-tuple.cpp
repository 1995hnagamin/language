#include <iostream>
#include <tuple>

int
main(int argc, char* argv[]) {
  std::tuple<> t = std::make_tuple();
  std::tie() = t;
  t = std::tuple_cat(t, t);
  std::cout << std::tuple_size<decltype(t)>::value << std::endl;
  return 0;
}
