#include <cassert>
#include <cctype>
#include <string>

class ci_string {
  public:
  ci_string(const std::string& str) : value(str) {
    for(auto&& c : value) {
      c = std::tolower(c);
    }
  }
  operator std::string() {
    return value;
  }
  private:
  std::string value;
};

int main() {
  ci_string s("AbCdE");
  assert(s == "ABCDE");
  assert(s == "abcde");
  return 0;
}