struct A {
	struct B {
		int i;
	} a;
	double d;
};

int main() {
	struct A a;
	struct B b;
	a.d = 10;
	b.i = 20;
	return 0;
}
