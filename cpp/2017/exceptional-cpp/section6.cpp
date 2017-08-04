#include <list>
#include <string>

struct Employee {
  std::string addr;
  std::string name;
};

bool operator==(Employee const &emp, std::string const &str) {
  return emp.name == str;
}

std::string FindAddr(std::list<Employee> emps, std::string name) { // const&
  for ( std::list<Employee>::iterator i = emps.begin();
        i != emps.end(); // emps.end() ?
        i++) // ++i
  {
    if (*i == name) {
      return i->addr;
    }
  }
  return "";
}

int main() {
  return 0;
}
