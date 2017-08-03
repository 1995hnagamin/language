#include <cassert>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

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

bool same_sign(int x, int y) {
  return ((x ^ y) >= 0);
}

void test_memicmp(char const *s1, char const *s2, size_t size, int answer) {
  if (!same_sign(memicmp(s1, s2, size), answer)) {
    std::cout
    << "!!! "
    << s1
    << (answer == 0 ? " == " : (answer > 0 ? " > " : " < "))
    << s2
    << std::endl;
  std::abort();
  }
}

int main() {
  ci_string s("AbCdE");
  assert(s == "ABCDE");
  assert(s == "abcde");
  assert(s < "AbCdEf");
  assert("AbCdEf" > s);
  assert(s > "");
  assert("" < s);
  assert(ci_string("") == ci_string(""));

  std::vector<std::tuple<char const*, char const*, size_t, int>> const testcases = {
    std::make_tuple("typedef", "toupper", 1, 0),
    std::make_tuple("", "", 0, 0),
    std::make_tuple("", "", 10, 0),
    std::make_tuple("typedef", "toupper", 1, 0),
    std::make_tuple("assert", "typedef", 0, 0),
    std::make_tuple("which", "WHICH", 4, 0),
    std::make_tuple("when", "whenever", 5, -1),
    std::make_tuple("", "s", 5, -1),
  };
  for (auto&& testcase : testcases) {
    char const *s1;
    char const *s2;
    size_t size;
    int answer;
    std::tie(s1, s2, size, answer) = testcase;
    test_memicmp(s1, s2, size, answer);
    test_memicmp(s2, s1, size, -answer);
  }
  return 0;
}