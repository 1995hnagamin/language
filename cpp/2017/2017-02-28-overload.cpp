class A {

};

class B : public A {
public:
  B(const A& x): A(), a(x) {
  }
  B(const B&) = default;
  A a;
};

int main() {
  A a;
  B b1(a);
  B b2 = b1;
}
