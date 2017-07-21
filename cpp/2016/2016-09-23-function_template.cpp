template<typename T>
T square(T x) {
  return x * x;
}

template<typename T>
T cube(T x) {
  return x * x * x;
}

using func = int(*)(int);

template<typename T>
using conversion = T(*)(T);

int main() {
  // int (*f)(int) = (true? (func)&square:(func)&cube); // not error
  // int (*g)(int) = &square;                 // not error
  // int x = static_cast<int(*)(int)>(true ? &square : &cube)(2); error
  int (*f)(int) = (true? (conversion<int>)&square:(conversion<int>)&cube);
  int (*g)(int) = (true? (conversion)&square:(conversion)&cube);
}
