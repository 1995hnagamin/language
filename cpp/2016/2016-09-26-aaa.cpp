template <typename T>
int f(T) {
  return 0;
}

int main() {
  int (*fp)(int) = f<const int>;
}
