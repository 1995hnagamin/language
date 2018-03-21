template<typename T>
class A {
  public:
    int func();
    T zero();
};

template<typename T>
T A<T>::zero() {
  return T(0);
}

int main() {
  A<int> obj;
  return obj.zero();
}
