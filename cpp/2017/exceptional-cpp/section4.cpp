#include <algorithm>
#include <cstdlib>
#include <iostream>

template<typename T, size_t size>
class fixed_vector {
  public:
  typedef T*        iterator;
  typedef T const*  const_iterator;

  fixed_vector()
    : v_(new T[size])
  {
    std::cout << "#1" << std::endl;
  }
  ~fixed_vector() {
    delete[] v_;
  }
  template<typename O, size_t osize>
  fixed_vector(const fixed_vector<O, osize> &other)
    : v_(new T[size])
  {
    std::cout << "#2" << std::endl;
    std::copy(
      other.cbegin(),
      other.cbegin() + std::min(size, osize),
      begin());
  }
  void Swap(fixed_vector &other) noexcept {
    using std::swap;
    swap(v_, other.v_);
  }
  template<typename O, size_t osize>
  fixed_vector<T, size>&
  operator=(const fixed_vector<O, osize> &rhs) {
    fixed_vector<T, size> temp(rhs);
    Swap(temp);
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
  T *v_;
};

int main() {
  fixed_vector<char, 4> v;
  fixed_vector<int, 4> w;
  fixed_vector<int, 4> w2(w); // implicitly-defined copy ctor called
  fixed_vector<int, 4> w3(v); // template ctor called
  w = w2; // implicitly-defined operator= called
  w = v;  // template operator= called
  return 0;
}
