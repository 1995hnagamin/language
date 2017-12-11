int func1(int x, int (*fp)(int x, double y)); // OK
int func2(int a, int (*fp)(int x, double x)); // error
int func3(int x, double x); // error
