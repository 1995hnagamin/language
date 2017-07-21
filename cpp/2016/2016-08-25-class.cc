class Hoge {
  void private_method();
  int poe;
  public:
  Hoge() try : poe(42) {;} catch (int e) {}
  int public_method();
};

class Fuga : public Hoge {
  int popo;
};
