#include <iostream>
#include <memory>
#include <string>

using Money = int;
using String = std::string;

class Employee {
  public:
    String Title() const;
    Money Salary() const;
    String First() const;
    String Last() const;
};


std::unique_ptr<String> EvaluateSalaryAndReturnName(Employee e) {
  std::unique_ptr<String> result(new String(e.First() + " " + e.Last()));
  if (e.Title() == "CEO" || e.Salary() > 100000) {
    String message = (*result) + " is overpaid\n";
    std::cout << message;
  }
  return result;
}
