template<typename T>
int func(const T&) {
  return 0;
}

template<>
int func<double>(const double&) {
  return 100;
}


int main() {
  auto val = func(0);
}
