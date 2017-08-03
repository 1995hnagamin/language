#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using Date = std::string;

Date TodaysDate() {
  return Date();
}

int main() {
  std::vector<Date> e;
  std::copy(std::istream_iterator<Date>(std::cin),
    std::istream_iterator<Date>(), // ??
    std::back_inserter(e));
  std::vector<Date>::iterator first =
    std::find(e.begin(), e.end(), "01/01/95");
  std::vector<Date>::iterator last =
    std::find(e.begin(), e.end(), "12/31/95");
  *last = "12/31/95"; // M[last == e.end()]
  std::copy(
    first,
    last,
    std::ostream_iterator<Date>(std::cout, "\n"));
  e.insert(--e.end(), TodaysDate());
  std::copy(
    first,
    last,
    std::ostream_iterator<Date>(std::cout, "\n"));

  return 0;
}