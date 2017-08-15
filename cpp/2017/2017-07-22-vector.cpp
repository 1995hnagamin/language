#include <vector>
#include <functional>

void func() {
  int i = 10;
  std::vector<void(*)()> vf(i);
  std::function<void()> *pf = new std::function<void()>[i];
}
