struct A {
	struct B;
	struct B *ptr1;
};

struct B {
	struct B *ptr2;
};
