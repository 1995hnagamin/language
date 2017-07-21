namespace NS1 {
  class A {
    public:
      A operator /(const A& other);
  };

  A operator- (const A& lhs, const A& rhs);
}

NS1::A operator+ (const NS1::A& lhs, const NS1::A& rhs); 

int main() {
  NS1::A a1, a2;

  a1 / a2;
  a1 - a2;
  a1 + a2;

  a1.operator/(a2);
  operator+(a1, a2);
  operator-(a1, a2);
  // operator/(a1, a2); - error
  (operator+)(a1, a2);
  // (operator-)(a1, a2); - error
}
