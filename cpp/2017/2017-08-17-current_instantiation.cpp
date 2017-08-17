template<typename T>
class c1 {
  using name1 = c1; // (1a.1) x (1b.1)
                    // (1a.1) x (1b.2)
  class c2 {
    using name2 = c1; // (1a.2) x (1b.1)
    using name3 = c2; // (1a.2) x (1b.2)
  };

  void func1() {
    using name4 = c1; // (1a.3) x (1b.1)
                      // (1a.3) x (1b.2)
  }

  class c3 {
    void func2() {
      using name5 = c1; // (1a.4) x (1b.1)
      using name6 = c3; // (1a.4) x (1b.2)
    }
  };
};

template <typename T>
class c4 {
  using name7 = c4<T>; // (2.1)

  void func() {
    using name8 = c4<T>; // (2.2)
  }
};

template <typename T>
class c5 {
  class c6 {
    using name9 = c5::c6; // (3)
    // `c5` refers to the current instantiation ((1a.1)x(1b.1))
  };
};

template <typename T>
class c7 { };

template<typename T>
class c7<T**> {
  using name10 = c7<T**>; // (4)
};

template<typename T, typename... U>
class c8 { };

template<typename... U>
class c8<void, U...> {
  using name11 = c8<void, U...>;
};
