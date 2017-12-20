template <class T>
class MyList {
  public:
    bool Insert(const T &, size_t index);
    T Access(size_t index) const;
    size_t Size() const;

  private:
    T *buf_;
    size_t bufsize_;
};

template <class T>
class MySet1 : private MyList<T> {
  public:
    bool Add(const T &);
    T Get(size_t index) const;
    using MyList<T>::Size;
};

template <class T>
class MySet2 {
  public:
    bool Add(const T &);
    T Get(size_t index) const;
    size_t Size() const;

  private:
    MyList<T> impl_;
};
