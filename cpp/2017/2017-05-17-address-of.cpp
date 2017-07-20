#include <utility>

int main() {
  int i = 0;
  int *pi = &(std::move(i));
  return 0;
}
