#include <cassert>

template<bool B>
class Invert {
  public:
    static bool const result = !B;
    Invert(int x) { }
};

int const result = -1;

int main() {
  bool test1 = Invert<(1>0)>::result;
  assert(!test1);
}
