#include <initializer_list>
#include <string>
#include <tuple>

class Klass {
  public:
    Klass(int i, std::initializer_list<std::tuple<int, std::string>> c) {}
};

int main() {
  Klass k(100, {{1, "one"}, {2, "two"}});
  return 0;
}
