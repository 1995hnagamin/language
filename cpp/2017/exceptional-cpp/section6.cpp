#include <algorithm>
#include <list>
#include <string>

struct Employee {
  std::string addr;
  std::string name;
};

bool operator==(Employee const &emp, std::string const &str) {
  return emp.name == str;
}

std::string FindAddr(
  const std::list<Employee> &emps,
  const std::string &name) {
  std::list<Employee>::const_iterator const i(
    std::find(emps.begin(), emps.end(), name));
  if (i != emps.end()) {
    return i->addr;
  }
  return "";
}

int main() {
  return 0;
}
