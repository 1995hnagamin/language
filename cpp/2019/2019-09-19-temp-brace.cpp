template <typename T>
void func(T x) {
  T v { x };
}

int main() {
  int i = 100;
  func<int>(i);
  int &j = i;
  func< int& >(i);
  return 0;
}
