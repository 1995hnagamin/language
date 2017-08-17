template <typename T>
class BXT {
  public:
    typedef T Mystery;
    template<typename U>
    struct Magic;
};

template <typename T>
class DXTM : private BXT<T> {
  public:
    using BXT<T>::template Magic; // illegal (03, 11, 14)
    Magic<T> *plink;
};
