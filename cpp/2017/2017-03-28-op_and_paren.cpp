//#include <iostream>

namespace NS1 {

class A {
  public:
    A operator*(const A& a) {
//      std::cout << "NS1::A::operator*" << std::endl;
      return a;
    }
};

A operator*(const A&, const A& a) {
//  std::cout << "NS1::operator*" << std::endl;
  return a;
}

} // namespace NS1

NS1::A operator*(const NS1::A&, const NS1::A& a) {
//  std::cout << "::operator*" << std::endl;
  return a;
}

int main() {
  NS1::A a;
  (operator*)(a, a);
  // operator*(a, a); - error
  NS1::operator*(a, a);
  a.operator*(a);
}
