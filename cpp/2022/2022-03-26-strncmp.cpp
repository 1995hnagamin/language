#include <cstring>
#include <iostream>

char const *search(char const *str) {
  char const *begin = "the quick brown fox jumps over the lazy dog";
  char const *end = begin + std::strlen(begin);

  size_t n = std::strlen(str);
  for (char const *p = begin; p < end; ++p) {
    if (std::strncmp(p, str, n) == 0) {
      return p;
    }
  }
  return nullptr;
}

int main() {
  char const *p1 = search("brown");
  char const *p2 = search("dog");
  std::cout << (void*)p1 << "\n" << (void*)p2 << "\n";
  std::cout << p2 - p1 << "\n";
}
