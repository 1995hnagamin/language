namespace Hoge {
  int answer = 42;
  namespace Fuga {
    int func() {
      return answer;
    }
  };
};

int answer = 54;

int func() {
  return answer;
}

int anotherfunc() {
  using namespace Hoge::Fuga;
  return func();
}
