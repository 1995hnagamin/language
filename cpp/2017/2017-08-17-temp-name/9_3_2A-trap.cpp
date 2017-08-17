template<typename T>
class Trap {
  public:
    enum { x };
};

template<typename T>
class Victim {
  public:
    int y;
    void poof() {
      Trap< T > :: x * y;
    }
};

template<>
class Trap<void> {
  public:
    typedef int x;
};

/*
 *  Victim<void>::poof() {
 *    Trap < void > :: x * y;
 *  }
*/

void boom(Victim<void> &bomb) {
  bomb.poof();
}
