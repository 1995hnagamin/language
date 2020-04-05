#include <cstdlib>

class A {
  void *
    operator
    new
    [
    ]
      (size_t);

  template <typename T, typename S>
  T &
  operator
  ->*
  (S b);

  int
    operator
    (
    )
    (int i);
};
