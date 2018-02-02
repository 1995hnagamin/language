class A;

// class B : A { public: int i1; }; error

class C { public: int i2; };

class A : C { // OK
  public: int i3;
};
