#include <cassert>
#include <string>

int memicmp(char const *s1, char const *s2, size_t const n) {
  assert(s1 && s2);
  size_t i = 0;
  for (; i < n && *s1 && *s2; ++i, ++s1, ++s2) {
    char const c1 = toupper(*s1), c2 = toupper(*s2);
    if (c1 != c2) {
      return c1 < c2 ? -1 : 1;
    }
  }
  if ((*s1 || *s2) && i < n) {
    return (*s2) ? -1 : 1;
  }
    return 0;
}

struct ci_char_traits : public std::char_traits<char> {
  static bool eq(char c1, char c2) {
    return toupper(c1) == toupper(c2);
  }
  static bool lt(char c1, char c2) {
    return toupper(c1) < toupper(c2);
  }
  static int compare(char const *s1, char const *s2, size_t n) {
    return memicmp(s1, s2, n);
  }

  static char const *find(char const *s, int n, char c) {
    while (n-- > 0 && toupper(*s) != toupper(c)) {
      ++s;
    }
    return n > 0 ? s : 0;
  }
};

typedef std::basic_string<char, ci_char_traits> ci_string;

int main() {
  ci_string s("AbCdE");
  assert(s == "ABCDE");
  assert(s == "abcde");
  assert(s < "AbCdEf");
  assert("AbCdEf" > s);
  assert(s > "");
  assert("" < s);
  return 0;
}