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
std::list<Employee>::const_iterator end(emps.end());
for ( std::list<Employee>::const_iterator i = emps.cbegin();
      i != end;
      ++i)
{
  if (i->name == name) {
    return i->addr;
  }
}
return "";
}

int main() {
  return 0;
}
