#include <cstdlib>

template<typename T, size_t size>
class fixed_vector {
  public:
  typedef T*        iterator;
  typedef T const*  const_iterator;

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
};

int main() {
  return 0;
}
