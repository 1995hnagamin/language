#include <type_traits>
#include <iostream>

template <typename T1, typename T2>
class Parent {
public:
    Parent() = default;
    virtual ~Parent() = 0;
    virtual int function(T1 x, T2 y) {
        return 10;
    }
};

template <typename T1, typename T2>
Parent<T1, T2>::~Parent() = default;

template <typename T1, typename T2>
class Child : Parent<T1, T2> {
public:
    template <typename U = T2, typename std::enable_if<std::is_same<U, T1>::value, int>::type = 0>
    int function(T1 x, T2 y) override {
        return 42;
    }
};

int main() {
//    Child<double, double> c;
//    std::cout << c.function(0, 0) << std::endl;
    return 0;
}
