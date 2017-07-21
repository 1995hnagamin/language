#include <iostream>

class Base { };

class Derived : public Base { };

int main() {
  Base & base = *new Derived;
  delete &base;
}
