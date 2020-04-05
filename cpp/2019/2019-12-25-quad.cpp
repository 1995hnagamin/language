#include <cmath>
#include <iostream>
#include <string>

double quadr1(double a, double b, double c) {
  double const det = b * b - 4 * a * c;
  return (-b + sqrt(det)) / (2 * a);
}

double quadr2(double a, double b, double c) {
  double const det = b * b - 4 * a * c;
  return -2 * c / (b + sqrt(det));
}

int main() {
  double a, b;
  std::cin >> a >> b;

  std::cout << quadr1(1, a, b) << std::endl
            << quadr2(1, a, b) << std::endl;

  return 0;
}
