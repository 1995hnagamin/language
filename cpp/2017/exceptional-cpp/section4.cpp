#include <cstdlib>

template<typename T, size_t size>
class fixed_vector {
  public:
  typedef T*        iterator;
  typedef T const*  const_iterator;

  fixed_vector(const fixed_vector &other) {
    copy(other);
  }
  fixed_vector &operator=(const fixed_vector &rhs) {
    copy(rhs);
    return *this;
  }
  iterator begin() {
    return v_;
  }
  iterator end() {
    return v_ + size;
  }
  const_iterator cbegin() const {
    return v_;
  }
  const_iterator cend() const {
    return v_ + size;
  }

  private:
  T v_[size];

  void copy(fixed_vector const &other) {
    iterator dst = begin();
    for (const_iterator src = other.cbegin(); src != other.cend(); ++src, ++dst) {
      *dst = *src;
    }
  }
};

int main() {
  return 0;
}
