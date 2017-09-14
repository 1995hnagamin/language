#include <iostream>
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


String /* j */ EvaluateSalaryAndReturnName(Employee e /* x */) {
  /* a */
  if (e.Title() /* b */ == "CEO" || e.Salary() /* c */ > 100000) {
    std::cout
      << e.First() /* d */ << " " << e.Last() /* e */ << "is overpaid"
      << std::endl; /* f */
  }
  /* g */
  return e.First() /* h */ + " " + e.Last() /* i */;
}

/*
 * x
 * x a b
 * x a b c
 * x a b c d
 * x a b c d e
 * x a b c d e f g h
 * x a b c d e f g h i
 * x a b c d e f g h i j
 * x a b d
 * x a b d e
 * x a b d e f
 * x a b d e f g h
 * x a b d e f g h i
 * x a b d e f g h i j
 */
